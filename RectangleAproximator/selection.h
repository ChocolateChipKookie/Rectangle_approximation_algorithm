#pragma once
#include "solution.h"
#include <vector>
#include "rectangle_solution.h"

class selection
{
public:
	virtual std::vector<rectangle_solution*> select(std::vector<rectangle_solution*>& solutions, int count) = 0;
};
