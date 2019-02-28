#pragma once
#include <map>
#include <string>

class config
{
public:
	bool load(std::wstring& file_path);
	void save(std::wstring& file_path);

	unsigned population_size{ 0 };
	unsigned rectangles{ 0 };
	unsigned iterations_per_rectangle{ 0 };
	unsigned cleanup_iterations{ 0 };
	unsigned switches_after{ 0 };

	double mutations_secondary{ 0 };
	double mutations_secondary_2{ 0 };
	
	double mutations_last_rect{ 0 };
	double mutations_last_rect_2{ 0 };
	double mutations_last_rect_alpha{ 0 };
	double mutations_last_rect_alpha_2{ 0 };
	double mutations_last_rect_mutation{ 0 };
	double mutations_last_rect_mutation_2{ 0 };
	double mutations_last_rect_new{ 0 };
	double mutations_last_rect_new_2{ 0 };
	
	double mutations_background{ 0 };
	double mutations_background_2{ 0 };
	double mutations_background_alpha{ 0 };
	double mutations_background_alpha_2{ 0 };
	double mutations_background_mutation{ 0 };
	double mutations_background_mutation_2{ 0 };
	double mutations_background_new{ 0 };
	double mutations_background_new_2{ 0 };

	double mutations_random{ 0 };
	double mutations_random_2{ 0 };
	unsigned mutations_random_rectangles{ 0 };
	unsigned mutations_random_rectangles_2{ 0 };
	double mutations_random_alpha{ 0 };
	double mutations_random_alpha_2{ 0 };
	double mutations_random_mutation{ 0 };
	double mutations_random_mutation_2{ 0 };
	double mutations_random_new{ 0 };
	double mutations_random_new_2{ 0 };

	double mutations_swap{ 0 };
	double mutations_swap_2{ 0 };
	
	double mutations_new{ 0 };
	double mutations_new_2{ 0 };

	double crossover_chance{ 0 };
	double crossover_chance_2{ 0 };

	double selection_kfactor{ 0 };
	double selection_kfactor_2{ 0 };

private:
	bool fetch_value(std::map<std::string, std::string>& map, std::string str, unsigned& value);
	bool fetch_value(std::map<std::string, std::string>& map, std::string str, double& value);
	bool check(std::map<std::string, std::string>& map, std::string& str);
};
