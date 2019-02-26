#pragma once
#include "rectangle_solution.h"

class rectangle_crossover
{
public:
	virtual rectangle_solution* crossover(rectangle_solution* p1, rectangle_solution* p2) const = 0;
};
