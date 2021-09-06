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
		std::cout << n << "��° ������" << from << "���� " << to << "�� �Ű���ϴ�." << std::endl;
		return;
	}

	Hanoi_Recursion(n - 1, from, temp, to);
	std::cout << n << "��° ������" << from << "���� " << to << "�� �Ű���ϴ�." << std::endl;
	Hanoi_Recursion(n - 1, temp, to, from);
}
