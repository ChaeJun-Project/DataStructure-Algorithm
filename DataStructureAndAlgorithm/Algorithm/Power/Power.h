#pragma once

#include "../IAlgorithm.h"

class Power final : public IAlgorithm
{
public:
	Power(std::string algorithm_title);
	~Power();

	void Run() override;

	double Power_Recursion1(const double& num, const int& power); //power�� ����
	double Power_Recursion2(const double& num, const int& power); //log2 power�� ����
	double Power_Iteration(const double& num, const int& power);
};