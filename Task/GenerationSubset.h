#pragma once // подмножеств
#include <vector>
#include <iostream>
#include <string>
#include <fstream>

class Subset
{
private:
	int sizeSet;
	int sizeSubset;

	const int maskaForBit = 0x1;

	std::vector<int> set;
	std::vector<std::vector<int>> subset;

public:
	Subset(int sizeSet);

	std::vector<std::vector<int>> GetSubset();

	void Generetion();
};