#pragma once
#include "task.h"

class thread_poison: public task
{
public:
	std::vector<rectangle_solution*> run() override { return std::vector<rectangle_solution*>(); }

	bool is_poison() override { return true; }
};
