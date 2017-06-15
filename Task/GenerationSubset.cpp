#include "stdafx.h"
#include "GenerationSubset.h"

Subset::Subset(int sizeSet)
{
	this->sizeSet = sizeSet;
	this->sizeSubset = (int)pow(2, this->sizeSet);
	for (int i = 0; i < this->sizeSet; i++)
	{
		this->set.push_back(i);
	}
}

std::vector<std::vector<int>> Subset::GetSubset()
{
	return this->subset;
}

void Subset::Generetion()
{
	for (int i = 0; i < this->sizeSubset; i++)
	{
		int tempMask = i;
		std::vector<int> temp;
		for (int j = 0; j < this->sizeSet; j++)
		{
			if ((tempMask & this->maskaForBit) == 1)
			{
				temp.push_back(j);
			}
			tempMask >>= 1;
		}
		this->subset.push_back(temp);
	}
}