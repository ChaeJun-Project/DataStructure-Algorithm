#pragma once

#include "../IAlgorithm.h"

class Power final : public IAlgorithm
{
public:
	Power(std::string algorithm_title);
	~Power();

	void Run() override;

	double Power_Recursion1(const double& num, const int& power); //power번 수행
	double Power_Recursion2(const double& num, const int& power); //log2 power번 수행
	double Power_Iteration(const double& num, const int& power);
};