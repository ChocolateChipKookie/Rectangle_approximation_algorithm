#pragma once
#include <random>
#include <chrono>


class random_engine
{
public:

	random_engine(int seed = std::chrono::system_clock::now().time_since_epoch().count())
	{
		random.seed(seed);
	}

	random_engine(random_engine& r) = delete;
	random_engine(random_engine&& r) = delete;

	std::default_random_engine random;

	int get_random(std::uniform_int_distribution<int>& distribution)
	{
		return distribution(random);
	}

	int get_random(const int max)
	{
		return std::uniform_int_distribution<int>{0, max}(random);
	}

	int get_random(const int min, const int max)
	{
		return std::uniform_int_distribution<int>{min, max}(random);
	}

	double get_random_double()
	{
		static std::uniform_real_distribution<double> distribution;
		return distribution(random);
	}

	double get_random_gaussian(double mean, double sigma)
	{
		std::normal_distribution<double> distribution(mean, sigma);
		return distribution(random);
	}

};

namespace random
{
	thread_local static random_engine rng;
}