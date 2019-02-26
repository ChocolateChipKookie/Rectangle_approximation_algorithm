#include "background_mutation.h"
#include "random_engine.h"

rectangle_solution* background_mutation::mutate(rectangle_solution* parent) const
{
	auto& rand = random::rng;
	rectangle_solution* res = parent->clone();

	if (rand.get_random_double() < new_gene_chance_)
	{
		res->background_color[0] = rand.get_random(255);
		res->background_color[1] = rand.get_random(255);
		res->background_color[2] = rand.get_random(255);
	}
	else
	{
		if (rand.get_random_double() < mutation_chance_)
		{
			res->background_color[0] = static_cast<u_char>(static_cast<int>(res->background_color[0]) + rand.get_random_gaussian(0, alpha_color));
		}
		if (rand.get_random_double() < mutation_chance_)
		{
			res->background_color[1] = static_cast<u_char>(static_cast<int>(res->background_color[1]) + rand.get_random_gaussian(0, alpha_color));
		}
		if (rand.get_random_double() < mutation_chance_)
		{
			res->background_color[2] = static_cast<u_char>(static_cast<int>(res->background_color[2]) + rand.get_random_gaussian(0, alpha_color));
		}
	}

	return res;
}
