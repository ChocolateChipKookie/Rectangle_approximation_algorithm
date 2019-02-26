#pragma once

using u_char = unsigned char;

///3 dimensional color vector
using color = std::array<u_char, 3>;

///width, height
struct dimensions
{
	int width, height;
};

///Rectangle struct
///Variables: x, y, width, height, color
struct rectangle
{
	int x{ 0 }, y{ 0 }, width{ 0 }, height{ 0 };
	color color;
};