#pragma once
#include "rectangle_solution.h"

class rectangle_mutation
{
public:
	virtual rectangle_solution* mutate(rectangle_solution* parent) const = 0;
};
