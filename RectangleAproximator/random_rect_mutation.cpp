#include "random_rect_mutation.h"
#include "random_engine.h"

rectangle_solution* random_rect_mutation::mutate(rectangle_solution* parent) const
{
	rectangle_solution* res = parent->clone();
	auto& rand = random::rng;

	for(int i = 0; i < rectangles_; ++i)
	{
		rectangle& random_rect = res->get_rectangle(rand.get_random(res->get_last_position()));

		if (rand.get_random_double() < new_gene_chance_)
		{
			random_rect.color[0] = rand.get_random(255);
			random_rect.color[1] = rand.get_random(255);
			random_rect.color[2] = rand.get_random(255);

			random_rect.x = rand.get_random(dimensions_.width);
			random_rect.y = rand.get_random(dimensions_.height);
			random_rect.width = rand.get_random(dimensions_.width / 5);
			random_rect.height = rand.get_random(dimensions_.height / 5);
		}
		else
		{
			if (rand.get_random_double() < mutation_chance_)
			{
				random_rect.x += rand.get_random_gaussian(0, alpha_width_);
				if (random_rect.x < 0) random_rect.x = 0;
				else if (random_rect.x >= dimensions_.width) random_rect.x = dimensions_.width - 1;
			}
			if (rand.get_random_double() < mutation_chance_)
			{
				random_rect.y += rand.get_random_gaussian(0, alpha_height_);
				if (random_rect.y < 0) random_rect.y = 0;
				else if (random_rect.y >= dimensions_.height) random_rect.y = dimensions_.height - 1;
			}
			if (rand.get_random_double() < mutation_chance_)
			{
				random_rect.width += rand.get_random_gaussian(0, alpha_width_);
				if (random_rect.x + random_rect.width > dimensions_.width) random_rect.width = 0;
				else if (random_rect.x + random_rect.width > dimensions_.width) random_rect.width = dimensions_.width - random_rect.x - 1;
			}
			if (rand.get_random_double() < mutation_chance_)
			{
				random_rect.height += rand.get_random_gaussian(0, alpha_height_);
				if (random_rect.y + random_rect.height > dimensions_.height) random_rect.height = 0;
				else if (random_rect.y + random_rect.height > dimensions_.height) random_rect.height = dimensions_.height - random_rect.y - 1;
			}
			if (rand.get_random_double() < mutation_chance_)
			{
				random_rect.color[0] = static_cast<u_char>(static_cast<int>(random_rect.color[0]) + rand.get_random_gaussian(0, alpha_color_));
			}
			if (rand.get_random_double() < mutation_chance_)
			{
				random_rect.color[1] = static_cast<u_char>(static_cast<int>(random_rect.color[1]) + rand.get_random_gaussian(0, alpha_color_));
			}
			if (rand.get_random_double() < mutation_chance_)
			{
				random_rect.color[2] = static_cast<u_char>(static_cast<int>(random_rect.color[2]) + rand.get_random_gaussian(0, alpha_color_));
			}
		}
	}

	return res;
}
