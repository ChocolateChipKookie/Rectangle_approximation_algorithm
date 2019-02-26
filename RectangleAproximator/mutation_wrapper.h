#pragma once
#include "rectangle_mutation.h"

class mutation_wrapper
{
public:
	mutation_wrapper(rectangle_mutation& mutation, double percentage) : percentage_(percentage), mutation_(mutation) {}
	double percentage_;
	rectangle_mutation& mutation_;
};
