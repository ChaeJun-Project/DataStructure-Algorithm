#include "stdafx.h"

Factorial::Factorial(std::string algorithm_title)
	:IAlgorithm(algorithm_title)
{
}

Factorial::~Factorial()
{
}

void Factorial::Run()
{
}

int Factorial::Factorial_Recursion(const int & num)
{
	if (num == 1)
		return 1;

	return num * Factorial_Recursion(num - 1);
}

int Factorial::Factorial_Iteration(const int & num)
{
	int result = 1;

	for (int i = num; i > 0; --i)
	{
		result *= i;
	}

	return result;
}
