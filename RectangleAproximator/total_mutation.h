#pragma once
#include "rectangle_mutation.h"
#include "mutation_wrapper.h"
#include <vector>

class total_mutation : public rectangle_mutation
{
public:

	total_mutation(std::vector<mutation_wrapper> mutations, double secondary_chance);

	rectangle_solution* mutate(rectangle_solution* parent) const override;

private:
	std::vector<mutation_wrapper> mutations_;
	double secondary_chance_;

};
