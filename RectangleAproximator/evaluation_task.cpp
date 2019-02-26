#include "evaluation_task.h"
#include <chrono>

std::vector<rectangle_solution*> evaluation_task::run()
{
	for(auto& solution : to_evaluate)
	{
		canvas.clear(solution->background_color);
		for(unsigned i = 0; i < solution->current_rectangles; ++i)
		{
			canvas.draw_rectangle(solution->rectangles[i]);
		}

		solution->value = static_cast<double>(base.compare(canvas));
		solution->fitness = -solution->value;
	}

	return std::vector<rectangle_solution*>();
}
