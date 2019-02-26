#pragma once
#include "task.h"
#include "image.h"

class evaluation_task : public task
{
public:

	evaluation_task(image& base, std::vector<rectangle_solution*>& to_evaluate) : base(base), canvas(image(base.dimensions_.width, base.dimensions_.height)), to_evaluate(to_evaluate)
	{
	}

	std::vector<rectangle_solution*> run() override;

private:

	image &base;
	image canvas;
	std::vector<rectangle_solution*>& to_evaluate;

};
