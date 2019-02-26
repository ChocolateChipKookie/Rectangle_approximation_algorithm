#pragma once
class solution
{
public:
	virtual ~solution() = default;
	double value;
	double fitness;

	virtual solution* clone() = 0;
};

