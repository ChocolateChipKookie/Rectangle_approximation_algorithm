#include "swap_mutation.h"
#include "random_engine.h"

swap_mutation::swap_mutation(dimensions& dimensions) : dimensions_(dimensions)
{
}

rectangle_solution* swap_mutation::mutate(rectangle_solution* parent) const
{
	rectangle_solution* res = parent->clone();

	res->swap(random::rng.get_random(res->get_last_position()), res->get_last_position());
	res->set_random(res->get_last_position(), dimensions_);

	return res;
}
