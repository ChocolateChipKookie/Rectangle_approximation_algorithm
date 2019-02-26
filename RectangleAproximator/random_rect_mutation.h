#pragma once
#include "rectangle_mutation.h"

class random_rect_mutation : public rectangle_mutation
{
public:
	random_rect_mutation(const double alpha, const double mutation_chance, const double new_gene_chance, int rectangles, dimensions& dimenisons)
		:mutation_chance_(mutation_chance), new_gene_chance_(new_gene_chance), rectangles_(rectangles), dimensions_(dimenisons)
	{
		alpha_width_ = static_cast<int>(dimenisons.width * alpha);
		alpha_height_ = static_cast<int>(dimenisons.height * alpha);
		alpha_color_ = static_cast<int>(255 * alpha);
	}

	rectangle_solution* mutate(rectangle_solution* parent) const override;
	
private:
	int alpha_width_;
	int alpha_height_;
	int alpha_color_;

	double mutation_chance_;
	double new_gene_chance_;
	int rectangles_;
	dimensions dimensions_;
};
