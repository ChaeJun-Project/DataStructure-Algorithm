#pragma once

#include "stdafx.h"

class IAlgorithm
{
public:
	IAlgorithm() = default;
	IAlgorithm(std::string algorithm_title)
		:algorithm_title(algorithm_title)
	{

	}

	virtual ~IAlgorithm()
	{

	}

	virtual void Start()
	{
		std::cout << algorithm_title << "알고리즘" << std::endl;
		std::cout << "============================================================================" << std::endl;
		start_time = clock();
	}

	virtual void Run() = 0;

	virtual void End()
	{
		end_time = clock();
		elapsed_time = static_cast<double>((end_time - start_time) / CLOCKS_PER_SEC);
		std::cout << "경과시간: " << elapsed_time << "초" << std::endl;
		std::cout << "============================================================================" << std::endl;
	}


protected:
	std::string algorithm_title;

	double elapsed_time;
	clock_t start_time;
	clock_t end_time;

};