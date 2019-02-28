#pragma once
#include "rectangle_mutation.h"

class swap_mutation : public rectangle_mutation
{
public:

	swap_mutation(dimensions& dimensions_);

	rectangle_solution* mutate(rectangle_solution* parent) const override;

private:
	dimensions& dimensions_;
};
