#include "rectangle_solution.h"
#include <random>
#include "random_engine.h"

rectangle_solution::rectangle_solution(unsigned size, unsigned start_rectangles, dimensions dimensions) : size(size)
{
	rectangles = new rectangle[size];
	current_rectangles = start_rectangles;

	auto& rand = random::rng;

	for(unsigned i = 0; i < start_rectangles; ++i)
	{
		rectangles[i].color[0] = rand.get_random(255);
		rectangles[i].color[1] = rand.get_random(255);
		rectangles[i].color[2] = rand.get_random(255);

		rectangles[i].x = rand.get_random(dimensions.width);
		rectangles[i].y = rand.get_random(dimensions.height);
		rectangles[i].width = rand.get_random(rectangles[i].x, dimensions.width - rectangles[i].x);
		rectangles[i].height = rand.get_random(rectangles[i].y, dimensions.height - rectangles[i].y);
	}

}

rectangle_solution::rectangle_solution(unsigned size) : size(size), rectangles(new rectangle[size])
{
}

rectangle_solution::rectangle_solution(rectangle_solution& rs) : size(rs.size), rectangles(new rectangle[size])
{
	fitness = rs.fitness;
	value = rs.value;
	background_color = rs.background_color;
	current_rectangles = rs.current_rectangles;
	std::copy(rs.rectangles, rs.rectangles + rs.size, rectangles);
}

rectangle_solution::rectangle_solution(rectangle_solution&& rs) :size(rs.size)
{
	rectangles = rs.rectangles;
	rs.rectangles = nullptr;
	fitness = rs.fitness;
	value = rs.value;
	background_color = rs.background_color;
	current_rectangles = rs.current_rectangles;
}

rectangle_solution::~rectangle_solution()
{
	delete[]rectangles;
}

rectangle& rectangle_solution::get_rectangle(unsigned position) const
{
	return rectangles[position];
}

unsigned rectangle_solution::get_last_position() const
{
	return current_rectangles - 1;
}

bool rectangle_solution::full() const
{
	return current_rectangles >= size;
}

void rectangle_solution::set_random(unsigned position, dimensions& bounds) const
{
	rectangles[position].x = random::rng.get_random(bounds.width);
	rectangles[position].y = random::rng.get_random(bounds.height);
	//rectangles[position].width = random::rng.get_random((bounds.width - rectangles[position].x) / 10);
	rectangles[position].width = 1;
	//rectangles[position].height = random::rng.get_random((bounds.height - rectangles[position].y) / 10);
	rectangles[position].height = 1;

	static std::uniform_int_distribution<int> char_distribution(0, 255);

	rectangles[position].color.at(0) = static_cast<u_char>(random::rng.get_random(char_distribution));
	rectangles[position].color.at(1) = static_cast<u_char>(random::rng.get_random(char_distribution));
	rectangles[position].color.at(2) = static_cast<u_char>(random::rng.get_random(char_distribution));
}

void rectangle_solution::add_new_random(dimensions& dimensions)
{
	if (full())return;
	current_rectangles++;
	set_random(get_last_position(), dimensions);
}

void rectangle_solution::swap(unsigned pos1, unsigned pos2) const
{
	if (pos1 >= static_cast<unsigned>(current_rectangles) || pos2 >= static_cast<unsigned>(current_rectangles)) return;
	std::swap(rectangles[pos1], rectangles[pos2]);
}

rectangle_solution* rectangle_solution::clone()
{
	return new rectangle_solution(*this);
}
