#pragma once
#include "rectangle_solution.h"
#include "rectangle_crossover.h"

class generic_crossover : public rectangle_crossover
{
public:
	generic_crossover(const double crossover_chance, const bool elitist) : crossover_chance_(crossover_chance), elitist_(elitist){}

	rectangle_solution* crossover(rectangle_solution* p1, rectangle_solution* p2) const override;

private:
	double crossover_chance_;
	bool elitist_;

};
