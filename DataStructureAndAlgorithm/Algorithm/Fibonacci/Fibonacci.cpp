#include "stdafx.h"

Fibonacci::Fibonacci(std::string algorithm_title)
	:IAlgorithm(algorithm_title)
{
}

Fibonacci::~Fibonacci()
{
}

void Fibonacci::Run()
{
}

int Fibonacci::Fibonacci_Recursion(const int & num)
{
	if (num == 1 || num == 2)
		return 1;

	return Fibonacci_Recursion(num - 1) + Fibonacci_Recursion(num - 2);
}

int Fibonacci::Fibonacci_Iteration(const int & num)
{
	if (num == 1 || num == 2)
		return 1;

	int result = 0;
	int temp1 = 1;
	int temp2 = 1;

	for (int i = 0; i < num - 2; i++)
	{
		result = temp1 + temp2;

		temp1 = temp2;
		temp2 = result;
	}

	return result;
}