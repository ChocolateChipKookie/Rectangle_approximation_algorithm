#include "tournament.h"
#include "random_engine.h"

std::vector<rectangle_solution*> tournament::select(std::vector<rectangle_solution*>& solutions, int count)
{
	std::vector<rectangle_solution*> result;

	for(int counter = 0; counter < count; ++counter)
	{		
		std::vector<rectangle_solution*> tmp_results;

		for(int k = 0; k < k_; ++k)
		{
			rectangle_solution* tmp_ptr;
			do
			{
				tmp_ptr = solutions[random::rng.get_random(solutions.size() - 1)];
			} 
			while (
				std::find(tmp_results.begin(), tmp_results.end(), tmp_ptr) != tmp_results.end() ||
				std::find(result.begin(), result.end(), tmp_ptr) != result.end()
				);

			tmp_results.push_back(tmp_ptr);
		}

		rectangle_solution* s = *std::max_element(tmp_results.begin(), tmp_results.end(), [](solution *s1, solution *s2) {return s1->fitness < s2->fitness; });
		result.push_back(s);
	}

	return result;
}
