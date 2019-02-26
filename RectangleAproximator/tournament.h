#pragma once
#include "selection.h"

class tournament : public selection
{
public:
	tournament(int k) : k_{ k } {}	
	std::vector<rectangle_solution*> select(std::vector<rectangle_solution*>& solutions, int count = 1) override;
private:
	int k_;
};
