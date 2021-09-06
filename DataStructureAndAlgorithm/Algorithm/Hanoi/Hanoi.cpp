#include "stdafx.h"
#include "Hanoi.h"

Hanoi::Hanoi(std::string algorithm_title)
{
}

Hanoi::~Hanoi()
{
}

void Hanoi::Run()
{
}

void Hanoi::Hanoi_Recursion(const int & n, const char & from, const char & to, const char & temp)
{
	if (n == 1)
	{
		std::cout << n << "번째 원반을" << from << "에서 " << to << "로 옮겼습니다." << std::endl;
		return;
	}

	Hanoi_Recursion(n - 1, from, temp, to);
	std::cout << n << "번째 원반을" << from << "에서 " << to << "로 옮겼습니다." << std::endl;
	Hanoi_Recursion(n - 1, temp, to, from);
}
