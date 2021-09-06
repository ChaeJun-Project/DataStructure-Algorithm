#pragma once

#include "../IAlgorithm.h"

class Fibonacci final: public IAlgorithm
{
public:
	Fibonacci(std::string algorithm_title);
	~Fibonacci();

	void Run() override;

	int Fibonacci_Recursion(const int& num);
	int Fibonacci_Iteration(const int& num);

};
