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
		std::cout << algorithm_title << "�˰���" << std::endl;
		std::cout << "============================================================================" << std::endl;
		start_time = clock();
	}

	virtual void Run() = 0;

	virtual void End()
	{
		end_time = clock();
		elapsed_time = static_cast<double>((end_time - start_time) / CLOCKS_PER_SEC);
		std::cout << "����ð�: " << elapsed_time << "��" << std::endl;
		std::cout << "============================================================================" << std::endl;
	}


protected:
	std::string algorithm_title;

	double elapsed_time;
	clock_t start_time;
	clock_t end_time;

};