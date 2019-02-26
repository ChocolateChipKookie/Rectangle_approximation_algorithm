#pragma once
#include "rectangle_mutation.h"

class swap_mutation : public rectangle_mutation
{
public:

	swap_mutation(unsigned swaps = 1);

	rectangle_solution* mutate(rectangle_solution* parent) const override;

private:
	unsigned swaps_;
};
