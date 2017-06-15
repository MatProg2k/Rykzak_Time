#pragma once
#include "GenerationSubset.h"

#include <iostream>
#include <vector>
#include <string>
#include <random>

class Knapsack
{
	std::vector<std::vector<int>> vectorThings;
	std::vector<int> vectorWeights;
	std::vector<int> vectorPrice;

	std::vector<int> resultVectorThings;
	std::vector<int> resultVectorWeights;
	std::vector<int> resultVectorPrise;

	int SumWeigth;
	int SumPrice;

	int sizeThing;
	int maxWeigth;

	int maxWeigthThing;
	int minWeigthThing;
	int maxPriceThing;
	int minPriceThing;

public:
	Knapsack(int sizeThing, int maxWeight, int minWeigthThing, int maxWeigthThing, int minPriceThing, int maxPriceThing);

	void Generation();
	void Show();

private:
	void GenerationSubsetThings();
	void GenerationVectorWeights();
	void GenerationVectorPrice();
};
