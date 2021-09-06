#include "stdafx.h"
#include "Power.h"

Power::Power(std::string algorithm_title)
	:IAlgorithm(algorithm_title)
{
}

Power::~Power()
{
}

void Power::Run()
{
}

double Power::Power_Recursion1(const double & num, const int & power)
{
	if (power == 0)
		return 1.0;

	return num * Power_Recursion1(num, power - 1);
}

double Power::Power_Recursion2(const double & num, const int & power)
{
	if (power == 0)
		return 1.0;

	else if (power % 2 == 0)//Â¦¼ö
		return Power_Recursion2(num*num, power / 2);

	else if (power % 2 != 0)//È¦¼ö
		return num * Power_Recursion2(num*num, (power - 1) / 2);
}

double Power::Power_Iteration(const double & num, const int & power)
{
	double result = 1.0;

	for (int i = 0; i < power; ++i)
	{
		result *= num;
	}

	return result;
}
