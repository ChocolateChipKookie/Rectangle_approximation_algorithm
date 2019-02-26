#pragma once
#include <vector>
#include "rectangle_solution.h"

class task
{
public:
	virtual std::vector<rectangle_solution*> run() = 0;

	virtual bool is_poison() { return false; }
};
