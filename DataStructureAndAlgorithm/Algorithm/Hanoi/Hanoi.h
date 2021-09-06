#pragma once

#include "../IAlgorithm.h"

class Hanoi final : public IAlgorithm
{
public:
	Hanoi(std::string algorithm_title);
	~Hanoi();

	void Run() override;

	void Hanoi_Recursion(const int& n, const char& from, const char& temp, const char& to);
};