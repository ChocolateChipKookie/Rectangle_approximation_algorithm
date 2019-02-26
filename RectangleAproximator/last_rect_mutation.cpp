#include "last_rect_mutation.h"
#include "random_engine.h"

rectangle_solution* last_rect_mutation::mutate(rectangle_solution* parent) const
{
	rectangle_solution* res = parent->clone();;

	auto& rand = random::rng;
	
	rectangle& last = res->get_rectangle(res->get_last_position());

	if (rand.get_random_double() < new_gene_chance_)
	{
		last.color[0] = rand.get_random(255);
		last.color[1] = rand.get_random(255);
		last.color[2] = rand.get_random(255);

		last.x = rand.get_random(dimensions_.width);
		last.y = rand.get_random(dimensions_.height);
		last.width = rand.get_random(dimensions_.width / 5);
		last.height = rand.get_random(dimensions_.height / 5);
	}
	else
	{
		if (rand.get_random_double() < mutation_chance_)
		{
			last.x += rand.get_random_gaussian(0, alpha_width_);
			if (last.x < 0) last.x = 0;
			else if (last.x >= dimensions_.width) last.x = dimensions_.width - 1;
		}
		if (rand.get_random_double() < mutation_chance_)
		{
			last.y += rand.get_random_gaussian(0, alpha_height_);
			if (last.y < 0) last.y = 0;
			else if (last.y >= dimensions_.height) last.y = dimensions_.height - 1;
		}
		if (rand.get_random_double() < mutation_chance_)
		{
			last.width += rand.get_random_gaussian(0, alpha_width_);
			if (last.x + last.width > dimensions_.width) last.width = 0;
			else if (last.x + last.width > dimensions_.width) last.width = dimensions_.width - last.x - 1;
		}
		if (rand.get_random_double() < mutation_chance_)
		{
			last.height += rand.get_random_gaussian(0, alpha_height_);
			if (last.y + last.height > dimensions_.height) last.height = 0;
			else if (last.y + last.height > dimensions_.height) last.height = dimensions_.height - last.y - 1;
		}
		if (rand.get_random_double() < mutation_chance_)
		{
			last.color[0] = static_cast<u_char>(static_cast<int>(last.color[0]) + rand.get_random_gaussian(0, alpha_color_));
		}
		if (rand.get_random_double() < mutation_chance_)
		{
			last.color[1] = static_cast<u_char>(static_cast<int>(last.color[1]) + rand.get_random_gaussian(0, alpha_color_));
		}
		if (rand.get_random_double() < mutation_chance_)
		{
			last.color[2] = static_cast<u_char>(static_cast<int>(last.color[2]) + rand.get_random_gaussian(0, alpha_color_));
		}
	}

	return res;
}
