#pragma once
#include "dimensions.h"
#include "rectangle_solution.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui.hpp>
#include <memory>

class image
{
public:
	dimensions dimensions_;
	std::vector<color> data_;
	
	image(int width, int height);
	image(std::wstring& file_name);
	~image();

	dimensions get_dimensions() const;
	
	void clear(color color);
	void clear(u_char r, u_char g, u_char b);

	unsigned long long compare(image& other);
	
	std::vector<color>& get_data();
	void draw_rectangle(rectangle& rect, unsigned zoom = 1);
	void draw_rectangle(rectangle&& rect);
	void draw_solution(rectangle_solution& solution, unsigned zoom = 1);

	void save(std::wstring& file_name);
};
