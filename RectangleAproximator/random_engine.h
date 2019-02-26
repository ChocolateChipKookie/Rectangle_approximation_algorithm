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

	///Returns random number following the given distribution
	int get_random(std::uniform_int_distribution<int>& distribution)
	{
		return distribution(random);
	}

	///Generates random number in range [0, max]
	int get_random(const int max)
	{
		return std::uniform_int_distribution<int>{0, max}(random);
	}

	///Generates random number in range [min, max]
	int get_random(const int min, const int max)
	{
		return std::uniform_int_distribution<int>{min, max}(random);
	}

	///Generates random double in range [0, 1]
	double get_random_double()
	{
		static std::uniform_real_distribution<double> distribution;
		return distribution(random);
	}

	///Generates random number gaussian
	double get_random_gaussian(double mean, double sigma)
	{
		std::normal_distribution<double> distribution(mean, sigma);
		return distribution(random);
	}

};

namespace random
{
	///Thread local random number generator
	thread_local static random_engine rng;
}