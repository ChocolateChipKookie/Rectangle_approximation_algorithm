#pragma once
#include "rectangle_mutation.h"
class new_rect_mutation :
	public rectangle_mutation
{
public:
	new_rect_mutation(dimensions& dimensions);

	rectangle_solution* mutate(rectangle_solution* parent) const override;

private:
	dimensions& dimensions_;

};

