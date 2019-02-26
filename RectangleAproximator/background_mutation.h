#pragma once
#include "rectangle_mutation.h"

class background_mutation : public rectangle_mutation
{
public:

	background_mutation(const double alpha, const double mutation_chance, const double new_gene_chance)
		:alpha_color(static_cast<int>(255 * alpha)), new_gene_chance_(new_gene_chance), mutation_chance_(mutation_chance)
	{
	}

	rectangle_solution* mutate(rectangle_solution* parent) const override;

private:
	double alpha_color;
	double new_gene_chance_;
	double mutation_chance_;

};
