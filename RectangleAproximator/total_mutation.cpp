#include "total_mutation.h"
#include "random_engine.h"

total_mutation::total_mutation(std::vector<mutation_wrapper> mutations, double secondary_chance) 
	: mutations_(mutations), secondary_chance_(secondary_chance)
{
	double sum = 0;
	for (auto& m : mutations_)
	{
		sum += m.percentage_;
	}
	for (auto& m : mutations_)
	{
		m.percentage_ /= sum;
	}
}

rectangle_solution* total_mutation::mutate(rectangle_solution* parent) const
{
	auto& rand = random::rng;
	rectangle_solution* result{ nullptr };

	do
	{
		double decider = random::rng.get_random_double();
		
		for (auto& m : mutations_)
		{
			decider -= m.percentage_;
			if (decider <= 0.)
			{
				delete result;
				result = m.mutation_.mutate(parent);
				break;
			}
		}

		if (!(decider <= 0.))
		{
			//Should never happen
			throw std::runtime_error{ "Error in total mutation_!" };
		}
	} while (rand.get_random_double() < secondary_chance_);

	return result;
}