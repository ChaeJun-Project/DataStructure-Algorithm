#pragma once

#include "../IAlgorithm.h"

class Factorial final : public IAlgorithm
{
public:
	Factorial(std::string algorithm_title);
	~Factorial();

	void Run() override;

	int Factorial_Recursion(const int& num);
	int Factorial_Iteration(const int& num);
};