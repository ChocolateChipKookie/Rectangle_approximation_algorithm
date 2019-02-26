#include "genetic_algorithm.h"
#include "thread_poison.h"
#include "evaluation_task.h"

genetic_algorithm::genetic_algorithm(
	rectangle_mutation& mutation,
	rectangle_mutation& mutation_after,
	rectangle_crossover& crossover,
	rectangle_crossover& crossover_after,
	selection& selection,
	::selection& selection_after,
	const unsigned cleanup_after,
	const unsigned population_size,
	const unsigned iterations_per_rect,
	const unsigned rectangles,
	const unsigned iterations_after,
	image& goal_image)
	:	mutation_(mutation),
		mutation_after_(mutation_after),
		crossover_(crossover),
		crossover_after_(crossover_after),
		selection_(selection),
		selection_after_(selection_after),
		goal_image_(goal_image),
		population_size_(population_size),
		iterations_till_new_(iterations_per_rect),
		iterations_after_(iterations_after),
		rectangles_(rectangles),
		cleanup_after_(cleanup_after)
{
	int tmp = rectangles;
	while(tmp - cleanup_after > 0)
	{
		switch_schedule_.emplace_back(cleanup_after);
		tmp -= cleanup_after;
	}

	switch_schedule_.emplace_back(tmp);

	const unsigned threads = std::thread::hardware_concurrency();
	for(unsigned i = 0; i < threads; ++i)
	{
		threads_.emplace_back(thread_worker, &src_queue_, &dest_queue_);
	}
}

genetic_algorithm::~genetic_algorithm()
{
	//Stops all threads
	thread_poison poison;
	for(unsigned i = 0, threads = threads_.size(); i < threads; ++i)
	{
		src_queue_.push(&poison);
	}

	for(auto& thread : threads_)
	{
		thread.join();
	}
	delete best_solution;
}

void genetic_algorithm::run(genetic_algorithm* ga)
{
	std::vector<rectangle_solution*> population;
	population.reserve(ga->population_size_);

	for(unsigned i = 0; i < ga->population_size_; ++i)
	{
		population.push_back(new rectangle_solution(ga->rectangles_));
	}

	int it{ 0 };

	for(unsigned s : ga->switch_schedule_)
	{
		for (unsigned rects = 0; rects < s; ++rects)
		{
			if (it != 0)
			{
				delete_population(population);
				for (auto& solution : population)
				{
					solution = new rectangle_solution(*(ga->best_solution));
				}
			}

			for (auto& solution : population)
			{
				solution->add_new_random(ga->goal_image_.dimensions_);
			}

			for (unsigned iter = 0; iter < ga->iterations_till_new_; ++iter)
			{
				if (ga->stop_)
				{
					delete_population(population);
					return;
				}
				std::lock_guard<std::mutex> lg(ga->run_mutex);

				ga->current_iteration = it++;
				ga->evaluate(population);

				rectangle_solution* b = *std::max_element(population.begin(), population.end(), [](solution *s1, solution *s2) {return s1->fitness < s2->fitness; });

				if (ga->best_solution == nullptr || b->fitness > ga->best_solution->fitness)
				{
					std::lock_guard<std::mutex> lg(ga->best_solution_mutex);
					delete[] ga->best_solution;
					ga->best_solution = new rectangle_solution(*b);
				}

				const auto new_generation = ga->generate_population(population, ga->crossover_, ga->selection_);
				delete_population(population);
				population = new_generation;
				mutate_population(population, ga->mutation_);
			}
		}

		delete_population(population);
		for (auto& solution : population)
		{
			solution = new rectangle_solution(*(ga->best_solution));
		}

		for (unsigned iter = 0; iter < ga->iterations_after_; ++iter)
		{
			if (ga->stop_)
			{
				delete_population(population);
				return;
			}
			std::lock_guard<std::mutex> lg(ga->run_mutex);

			ga->current_iteration = it++;
			ga->evaluate(population);

			rectangle_solution* b = *std::max_element(population.begin(), population.end(), [](solution *s1, solution *s2) {return s1->fitness < s2->fitness; });

			if (ga->best_solution == nullptr || b->fitness > ga->best_solution->fitness)
			{
				delete[] ga->best_solution;
				ga->best_solution = new rectangle_solution(*b);
			}

			const auto new_generation = ga->generate_population(population, ga->crossover_after_, ga->selection_after_);
			delete_population(population);
			population = new_generation;
			mutate_population(population, ga->mutation_after_);
		}
	}

	while(!ga->stop_)
	{
		ga->current_iteration = it++;

		ga->evaluate(population);

		rectangle_solution* b = *std::max_element(population.begin(), population.end(), [](solution *s1, solution *s2) {return s1->fitness < s2->fitness; });

		if (ga->best_solution == nullptr || b->fitness > ga->best_solution->fitness)
		{
			delete[] ga->best_solution;
			ga->best_solution = new rectangle_solution(*b);
		}

		const auto new_generation = ga->generate_population(population, ga->crossover_after_, ga->selection_after_);
		delete_population(population);
		population = new_generation;
		mutate_population(population, ga->mutation_after_);
	}

	delete_population(population);
}

image& genetic_algorithm::get_goal_image() const
{
	return goal_image_;
}

void genetic_algorithm::stop()
{
	stop_ = true;
}

void genetic_algorithm::thread_worker(blocking_queue<task*>* src_queue, blocking_queue<std::vector<rectangle_solution*>>* dest_queue)
{
	while(true)
	{
		task* t  = src_queue->pop();
		if(t -> is_poison())
		{
			return;
		}
		dest_queue->push(t->run());
	}
}

void genetic_algorithm::evaluate(std::vector<rectangle_solution*> population)
{
	std::vector<std::vector<rectangle_solution*>> testers(threads_.size(), std::vector<rectangle_solution*>());

	unsigned pos { 0 };

	for(auto solution : population)
	{
		testers[pos].push_back(solution);
		pos = (pos + 1) % threads_.size();
	}

	std::vector<evaluation_task> tasks;
	tasks.reserve(threads_.size());

	for(unsigned i = 0; i < threads_.size(); ++i)
	{
		tasks.emplace_back(goal_image_, testers[i]);
		src_queue_.push(&tasks[i]);
	}

	for (unsigned i = 0; i < threads_.size(); ++i)
	{
		dest_queue_.pop();
	}

}

void genetic_algorithm::delete_population(std::vector<rectangle_solution*>& population)
{
	for(auto& individual : population)
	{
		delete individual;
	}
}

std::vector<rectangle_solution*> genetic_algorithm::generate_population(std::vector<rectangle_solution*>& population, rectangle_crossover& crossover, selection& selection) const
{
	std::vector<rectangle_solution*> result;
	result.reserve(population_size_);

	for(unsigned i = 0; i < population_size_; ++i)
	{
		std::vector<rectangle_solution*> parents = selection.select(population, 2);
		result.push_back(crossover.crossover(parents[0], parents[1]));
	}
	return result;
}

void genetic_algorithm::mutate_population(std::vector<rectangle_solution*>& population, rectangle_mutation& mutation)
{
	for (auto& i : population)
	{
		rectangle_solution* solution = mutation.mutate(i);
		delete i;
		i = solution;
	}
}
