#include "image.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

image::image(int width, int height) : dimensions_({width, height}), data_(std::vector<color>(width * height))
{}

image::image(std::wstring& file_name)
{
	std::ifstream f(file_name, std::iostream::binary);

	std::filebuf* pbuf = f.rdbuf();
	const size_t size = pbuf->pubseekoff(0, f.end, f.in);
	pbuf->pubseekpos(0, f.in);

	std::vector<uchar> buffer(size);
	pbuf->sgetn(reinterpret_cast<char*>(buffer.data()), size);

	cv::Mat im = imdecode(buffer, cv::IMREAD_COLOR);

	dimensions_ = { im.cols, im.rows };
	data_ = std::vector<color>(dimensions_.width * dimensions_.height);

	if (!im.data)
	{
		throw std::runtime_error{ "Error loading picture!" };
	}

	int pos = 0;
	for (int y = 0; y < dimensions_.height; ++y)
	{
		for (int x = 0; x < dimensions_.width; ++x)
		{
			cv::Vec3b vec = im.at<cv::Vec3b>(y, x);
			data_[pos].at(0) = vec[2];
			data_[pos].at(1) = vec[1];
			data_[pos].at(2) = vec[0];
			pos++;
		}
	}
}

image::~image() = default;

dimensions image::get_dimensions() const
{
	return dimensions_;
}

void image::clear(color color)
{
	for(auto& c : data_)
	{
		std::copy(color.begin(), color.end(), c.begin());
	}
}

void image::clear(u_char r, u_char g, u_char b)
{
	clear({ r, g, b });
}

unsigned long long image::compare(image& other)
{
	double total{ 0 };

	//If 2 images are compared and different, throw error
	if(!(other.dimensions_.width == dimensions_.width && other.dimensions_.height == dimensions_.height))
	{
		throw std::runtime_error{ "Dimensions of images don't match!" };
	}

	//Add all absolute differences
	for(unsigned i = 0; i < data_.size(); ++i)
	{
		total += std::abs(static_cast<int>(data_[i][0]) - static_cast<int>(other.data_[i][0]));// *0.2126;
		total += std::abs(static_cast<int>(data_[i][1]) - static_cast<int>(other.data_[i][1]));// * 0.7152;
		total += std::abs(static_cast<int>(data_[i][2]) - static_cast<int>(other.data_[i][2]));// * 0.0722;
	}

	return total;
}

std::vector<color>& image::get_data()
{
	return data_;
}

void image::draw_rectangle(rectangle& rect, unsigned zoom)
{
	//Set lower right
	int x1 = (rect.x + rect.width) * zoom;
	int y1 = (rect.y + rect.height) * zoom;
	if (x1 > dimensions_.width) x1 = dimensions_.width;
	if (y1 > dimensions_.height) y1 = dimensions_.height;

	//Fill
	for (int y = rect.y * zoom; y < y1; ++y)
	{
		for (int x = rect.x * zoom; x < x1; ++x)
		{
			std::copy(rect.color.begin(), rect.color.end(), data_[x + y * dimensions_.width].begin());
		}
	}
}

void image::draw_solution(rectangle_solution& solution, unsigned zoom)
{
	clear(solution.background_color);
	for (unsigned i = 0; i < solution.current_rectangles; ++i)
	{
		draw_rectangle(solution.rectangles[i], zoom);
	}
}

void image::save(std::wstring& file_name)
{
	cv::Mat im;

	//Draw image to mat
	im.create(dimensions_.height, dimensions_.width, CV_8UC3);
	int pos = 0;
	for (int y = 0; y < dimensions_.height; ++y)
	{
		for (int x = 0; x < dimensions_.width; ++x)
		{
			im.at<cv::Vec3b>(y, x)[0] = data_[pos].at(2);
			im.at<cv::Vec3b>(y, x)[1] = data_[pos].at(1);
			im.at<cv::Vec3b>(y, x)[2] = data_[pos].at(0);

			pos++;
		}
	}

	//Copy image to buffer
	std::vector<uchar> buf;
	cv::imencode(".jpg", im, buf);

	//Create out stream and save the image
	std::ofstream out_image(file_name, std::ios::out | std::ios::binary);
	out_image.write(reinterpret_cast<const char*>(buf.data()), buf.size());
}
