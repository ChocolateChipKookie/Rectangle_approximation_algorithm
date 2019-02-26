#pragma once
#include <vector>
#include <thread>
#include "blocking_queue.h"
#include "task.h"
#include "rectangle_mutation.h"
#include "rectangle_crossover.h"
#include "selection.h"
#include "image.h"

class genetic_algorithm
{
public:

	genetic_algorithm(
		rectangle_mutation& mutation, 
		rectangle_mutation& mutation_after, 
		rectangle_crossover& crossover, 
		rectangle_crossover& crossover_after, 
		::selection& selection, 
		::selection& selection_after,
		const unsigned cleanup_after,
		unsigned population_size,
		unsigned iterations_per_rect, 
		unsigned rectangles,
		unsigned iterations_after,
		image& goal_image);

	~genetic_algorithm();

	///Starts training
	static void run(genetic_algorithm* ga);

	//Best solution and mutex
	std::mutex best_solution_mutex;
	rectangle_solution* best_solution{ nullptr };

	unsigned current_iteration { 0 };

	image& get_goal_image() const;

	//Training pause mutex
	std::mutex run_mutex;
	///Stops algorithm
	void stop();

private:

	static void thread_worker(blocking_queue<task*>* src_queue, blocking_queue<std::vector<rectangle_solution*>>* dest_queue);
	void evaluate(std::vector<rectangle_solution*> population);
	static void delete_population(std::vector<rectangle_solution*>& population);
	std::vector<rectangle_solution*> generate_population(std::vector<rectangle_solution*>& population, rectangle_crossover& crossover, selection& selection) const;
	static void mutate_population(std::vector<rectangle_solution*>& population, rectangle_mutation& mutation);

	rectangle_mutation& mutation_;
	rectangle_mutation& mutation_after_;
	rectangle_crossover& crossover_;
	rectangle_crossover& crossover_after_;
	selection& selection_;
	selection& selection_after_;
	blocking_queue<task*> src_queue_;
	blocking_queue<std::vector<rectangle_solution*>> dest_queue_;

	image& goal_image_;

	unsigned population_size_;
	unsigned iterations_till_new_;
	unsigned iterations_after_;
	unsigned rectangles_;
	const unsigned cleanup_after_;
	std::vector<unsigned> switch_schedule_;

	bool stop_{ false };
	std::vector<std::thread> threads_;
};
