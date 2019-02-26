#include "generic_crossover.h"
#include "random_engine.h"

rectangle_solution* generic_crossover::crossover(rectangle_solution* p1, rectangle_solution* p2) const
{
	auto& rand = random::rng;

	if(elitist_)
	{
		if(p1->fitness < p2->fitness)
		{
			rectangle_solution* tmp = p1;
			p1 = p2;
			p2 = p1;
		}
	}

	rectangle_solution* res = p1->clone();

	for (int i = 0; i < res->current_rectangles; ++i) {
		if (rand.get_random_double() < crossover_chance_) {
			res->rectangles[i] = p2->rectangles[i];
		}
	}

	return res;
}
