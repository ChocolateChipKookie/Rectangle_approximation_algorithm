#include "config.h"
#include <fstream>
#include <QMessageBox>
#include <QFileDialog>

bool config::load(std::wstring& file_path)
{
	QFileInfo check_file(QString::fromStdWString(file_path));
	if (!(check_file.exists() && check_file.isFile())) {
		QMessageBox error_msg;
		error_msg.setText("Selected file doesn't exist!");
		error_msg.exec();
		return false;
	}

	std::ifstream input(file_path);

	std::string tmp;
	std::map<std::string, std::string> parameters;

	unsigned line{ 0 };
	while(std::getline(input, tmp))
	{
		line++;
		const unsigned delimiter = tmp.find(':');
		if(delimiter == std::string::npos)
		{
			QMessageBox error_msg;
			error_msg.setText(QString::fromStdString("Delimiter missing in line " + std::to_string(line) + " \"" + tmp + "\"!"));
			error_msg.exec();
			return false;
		}

		const unsigned from = delimiter + 1 + tmp.substr(delimiter + 1).find_first_not_of(" \t");
		const unsigned to = tmp.find_last_not_of(" \t\n\r");
		parameters[tmp.substr(0, delimiter)] = tmp.substr(from, to);
	}

	bool ret{ true };
	ret = ret && fetch_value(parameters, "Population size", population_size);
	ret = ret && fetch_value(parameters, "Rectangles", rectangles);
	ret = ret && fetch_value(parameters, "Iterations per rectangle", iterations_per_rectangle);
	ret = ret && fetch_value(parameters, "Cleanup iterations", cleanup_iterations);
	ret = ret && fetch_value(parameters, "Switches after", switches_after);
	
	ret = ret && fetch_value(parameters, "Secondary mutation(1)", mutations_secondary);
	ret = ret && fetch_value(parameters, "Secondary mutation(2)", mutations_secondary_2);
	
	ret = ret && fetch_value(parameters, "Last rectangle(1)", mutations_last_rect);
	ret = ret && fetch_value(parameters, "Last rectangle(2)", mutations_last_rect_2);
	ret = ret && fetch_value(parameters, "Last rectangle alpha(1)", mutations_last_rect_alpha);
	ret = ret && fetch_value(parameters, "Last rectangle alpha(2)", mutations_last_rect_alpha_2);
	ret = ret && fetch_value(parameters, "Last rectangle mutation(1)", mutations_last_rect_mutation);
	ret = ret && fetch_value(parameters, "Last rectangle mutation(2)", mutations_last_rect_mutation_2);
	ret = ret && fetch_value(parameters, "Last rectangle new gene(1)", mutations_last_rect_new);
	ret = ret && fetch_value(parameters, "Last rectangle new gene(2)", mutations_last_rect_new_2);
	
	ret = ret && fetch_value(parameters, "Background(1)", mutations_background);
	ret = ret && fetch_value(parameters, "Background(2)", mutations_background_2);
	ret = ret && fetch_value(parameters, "Background alpha(1)", mutations_background_alpha);
	ret = ret && fetch_value(parameters, "Background alpha(2)", mutations_background_alpha_2);
	ret = ret && fetch_value(parameters, "Background mutation(1)", mutations_background_mutation);
	ret = ret && fetch_value(parameters, "Background mutation(2)", mutations_background_mutation_2);
	ret = ret && fetch_value(parameters, "Background new gene(1)", mutations_background_new);
	ret = ret && fetch_value(parameters, "Background new gene(2)", mutations_background_new_2);
	
	ret = ret && fetch_value(parameters, "Random(1)", mutations_random);
	ret = ret && fetch_value(parameters, "Random(2)", mutations_random_2);
	ret = ret && fetch_value(parameters, "Random rectangle(1)", mutations_random_rectangles);
	ret = ret && fetch_value(parameters, "Random rectangle(2)", mutations_random_rectangles_2);
	ret = ret && fetch_value(parameters, "Random alpha(1)", mutations_random_alpha);
	ret = ret && fetch_value(parameters, "Random alpha(2)", mutations_random_alpha_2);
	ret = ret && fetch_value(parameters, "Random mutation(1)", mutations_random_mutation);
	ret = ret && fetch_value(parameters, "Random mutation(2)", mutations_random_mutation_2);
	ret = ret && fetch_value(parameters, "Random new gene(1)", mutations_random_new);
	ret = ret && fetch_value(parameters, "Random new gene(2)", mutations_random_new_2);
	
	ret = ret && fetch_value(parameters, "Swap(1)", mutations_swap);
	ret = ret && fetch_value(parameters, "Swap(2)", mutations_swap_2);
	ret = ret && fetch_value(parameters, "New(1)", mutations_new);
	ret = ret && fetch_value(parameters, "New(2)", mutations_new_2);
	ret = ret && fetch_value(parameters, "Crossover(1)", crossover_chance);
	ret = ret && fetch_value(parameters, "Crossover(2)", crossover_chance_2);
	ret = ret && fetch_value(parameters, "Selection k-number(1)", selection_kfactor);
	ret = ret && fetch_value(parameters, "Selection k-number(2)", selection_kfactor_2);

	return ret;
}

void config::save(std::wstring& file_path)
{
	std::ofstream output(file_path);

	output << "Population size: " << population_size << std::endl;
	output << "Rectangles: " << rectangles << std::endl;
	output << "Iterations per rectangle: " << iterations_per_rectangle << std::endl;
	output << "Cleanup iterations: " << cleanup_iterations << std::endl;
	output << "Switches after: " << switches_after << std::endl;

	output << "Secondary mutation(1): " << mutations_secondary << std::endl;
	output << "Secondary mutation(2): " << mutations_secondary_2 << std::endl;

	output << "Last rectangle(1): " << mutations_last_rect << std::endl;
	output << "Last rectangle(2): " << mutations_last_rect_2 << std::endl;
	output << "Last rectangle alpha(1): " << mutations_last_rect_alpha << std::endl;
	output << "Last rectangle alpha(2): " << mutations_last_rect_alpha_2 << std::endl;
	output << "Last rectangle mutation(1): " << mutations_last_rect_mutation << std::endl;
	output << "Last rectangle mutation(2): " << mutations_last_rect_mutation_2 << std::endl;
	output << "Last rectangle new gene(1): " << mutations_last_rect_new << std::endl;
	output << "Last rectangle new gene(2): " << mutations_last_rect_new_2 << std::endl;

	output << "Background(1): " << mutations_background << std::endl;
	output << "Background(2): " << mutations_background_2 << std::endl;
	output << "Background alpha(1): " << mutations_background_alpha << std::endl;
	output << "Background alpha(2): " << mutations_background_alpha_2 << std::endl;
	output << "Background mutation(1): " << mutations_background_mutation << std::endl;
	output << "Background mutation(2): " << mutations_background_mutation_2 << std::endl;
	output << "Background new gene(1): " << mutations_background_new << std::endl;
	output << "Background new gene(2): " << mutations_background_new_2 << std::endl;

	output << "Random(1): " << mutations_random << std::endl;
	output << "Random(2): " << mutations_random_2 << std::endl;
	output << "Random rectangle(1): " << mutations_random_rectangles << std::endl;
	output << "Random rectangle(2): " << mutations_random_rectangles_2 << std::endl;
	output << "Random alpha(1): " << mutations_random_alpha << std::endl;
	output << "Random alpha(2): " << mutations_random_alpha_2 << std::endl;
	output << "Random mutation(1): " << mutations_random_mutation << std::endl;
	output << "Random mutation(2): " << mutations_random_mutation_2 << std::endl;
	output << "Random new gene(1): " << mutations_random_new << std::endl;
	output << "Random new gene(2): " << mutations_random_new_2 << std::endl;

	output << "Swap(1): " << mutations_swap << std::endl;
	output << "Swap(2): " << mutations_swap_2 << std::endl;

	output << "New(1): " << mutations_new << std::endl;
	output << "New(2): " << mutations_new_2 << std::endl;

	output << "Crossover(1): " << crossover_chance << std::endl;
	output << "Crossover(2): " << crossover_chance_2 << std::endl;

	output << "Selection k-number(1): " << selection_kfactor << std::endl;
	output << "Selection k-number(2): " << selection_kfactor_2 << std::endl;
}

bool config::fetch_value(std::map<std::string, std::string>& map, std::string str, unsigned& value)
{
	if(check(map, str))
	{
		value = std::stoi(map[str]);
		return true;
	}

	QMessageBox error_msg;
	error_msg.setText(QString::fromStdString("Error loading: " + str));
	error_msg.exec();
	return false;
}

bool config::fetch_value(std::map<std::string, std::string>& map, std::string str, double& value)
{
	if (check(map, str))
	{
		value = std::stod(map[str]);
		return true;
	}

	QMessageBox error_msg;
	error_msg.setText(QString::fromStdString("Error loading: " + str));
	error_msg.exec();
	return false;
}

bool config::check(std::map<std::string, std::string>& map, std::string& str)
{
	return map.find(str) != map.end();
}

