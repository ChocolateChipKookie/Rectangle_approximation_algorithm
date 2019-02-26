#pragma once
#include "solution.h"
#include <array>
#include "dimensions.h"
#include "struct.h"
#include <vector>

///Rectangle solution class:
///Member variables:
///		One main Color
///		n Rectangles:
///			One color
///			Dimension
///			Position

class rectangle_solution : public solution
{
public:
	rectangle_solution(unsigned size, unsigned start_rectangles, dimensions dimensions);
	rectangle_solution(unsigned size);
	rectangle_solution(rectangle_solution& rs);
	rectangle_solution(rectangle_solution&& rs);
	~rectangle_solution();

	const unsigned size;

	unsigned current_rectangles{ 0 };
	rectangle* rectangles;
	color background_color{ 0 };

	rectangle& get_rectangle(unsigned position) const;
	unsigned get_last_position() const;
	bool full() const;
	void set_random(unsigned position, dimensions& bounds) const;
	void add_new_random(dimensions& dimensions);
	void swap(unsigned pos1, unsigned pos2) const;

	rectangle_solution* clone() override;
};
