#include "new_rect_mutation.h"
#include "random_engine.h"

new_rect_mutation::new_rect_mutation(dimensions& dimensions) : dimensions_(dimensions)
{
}

rectangle_solution* new_rect_mutation::mutate(rectangle_solution* parent) const
{
	rectangle_solution* res = parent->clone();

	int to_delete = random::rng.get_random(res->get_last_position() - 1);

	for(unsigned i = 0; i < res->current_rectangles; ++i)
	{
		res->rectangles[i] = res->rectangles[i + 1];
	}

	res->set_random(res->get_last_position(), dimensions_);

	return res;
}


