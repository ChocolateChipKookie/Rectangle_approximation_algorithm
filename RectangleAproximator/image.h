#pragma once
#include "dimensions.h"
#include "rectangle_solution.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui.hpp>
#include <memory>

class image
{
public:	
	image(int width, int height);
	image(std::wstring& file_name);
	~image();

	//Returns dimensions of image
	dimensions get_dimensions() const;

	///Clears image
	void clear(color color);

	///Clears image
	void clear(u_char r, u_char g, u_char b);

	///Compares current image with other image
	///Return: sum of all absolute differences
	unsigned long long compare(image& other);

	///Rectangle to the image
	///Rectangle can be zoomed by a factor
	void draw_rectangle(rectangle& rect, unsigned zoom = 1);
	
	///Solution to the image
	///Solution can be zoomed by a factor
	void draw_solution(rectangle_solution& solution, unsigned zoom = 1);

	///Gets data reference
	std::vector<color>& get_data();
	///Saves the image to a given file
	void save(std::wstring& file_name);

	dimensions dimensions_;
	std::vector<color> data_;
};
