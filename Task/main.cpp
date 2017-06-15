#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <locale>

#include "Knapsack.h"

int main()
{
	setlocale(LC_CTYPE, "Russian");

	std::ofstream file("Res.txt", std::ios::app);
	for (int i = 12; i < 21; i++)
	{
		clock_t start = clock();
		Knapsack knapsak(i, 300, 10, 300, 5, 55);
		knapsak.Generation();
		clock_t stop = clock();
		file << "Количество предметов: " << i << ", затраченное время: " << (long)(stop - start) << std::endl;
	}
	file.close();

	system("pause");
	return 0;
}