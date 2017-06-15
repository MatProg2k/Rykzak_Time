#include "stdafx.h"
#include "Knapsack.h"

Knapsack::Knapsack(int sizeThing, int maxWeight, int minWeigthThing, int maxWeigthThing, int minPriceThing, int maxPriceThing)
{
	this->sizeThing = sizeThing;
	this->maxWeigth = maxWeight;
	this->maxWeigthThing = maxWeigthThing;
	this->minWeigthThing = minWeigthThing;
	this->maxPriceThing = maxPriceThing;
	this->minPriceThing = minPriceThing;

	this->SumWeigth = 0;
	this->SumPrice = 0;

	this->GenerationVectorPrice();
	this->GenerationSubsetThings();
	this->GenerationVectorWeights();
}

void Knapsack::Show()
{
	std::cout << "Количество предметов: " << this->sizeThing << std::endl;
	std::cout << "Вместимость рюкзака, кг: " << this->maxWeigth << std::endl;
	std::cout << "Вектор предметов -> цен -> весов:" << std::endl;

	for (int i = 0; i < sizeThing; i++)
	{
		std::cout << char(97 + i) << " -> " << this->vectorPrice[i] << " -> " << this->vectorWeights[i] << std::endl;
	}

	std::cout << "Результирующий вектор предметов -> цен -> весов:" << std::endl;
	for (int i = 0; i < this->resultVectorThings.size(); i++)
	{
		std::cout << char(97 + this->resultVectorThings[i]) << " -> " << this->resultVectorPrise[i] << " -> " << this->resultVectorWeights[i] << std::endl;
	}
	std::cout << "Полученный вес: " << this->SumWeigth << std::endl;
	std::cout << "Полученная стоимость: " << this->SumPrice << std::endl;
}

void Knapsack::Generation()
{
	for (int i = 0; i < this->vectorThings.size(); i++)
	{
		int tempP = 0;
		int tempW = 0;

		for (int j = 0; j < this->vectorThings[i].size(); j++)
		{
			tempW += this->vectorWeights[this->vectorThings[i][j]];
			tempP += (this->vectorPrice[this->vectorThings[i][j]] * this->vectorWeights[this->vectorThings[i][j]]);
		}

		if ((tempP > this->SumPrice) && (tempW <= this->maxWeigth))
		{
			this->resultVectorPrise.clear();
			this->resultVectorThings.clear();
			this->resultVectorWeights.clear();

			for (int j = 0; j < this->vectorThings[i].size(); j++)
			{
				this->resultVectorPrise.push_back(this->vectorPrice[this->vectorThings[i][j]]);
				this->resultVectorWeights.push_back(this->vectorWeights[this->vectorThings[i][j]]);
				this->resultVectorThings.push_back(this->vectorThings[i][j]);
			}
			this->SumPrice = tempP;
			this->SumWeigth = tempW;
		}
	}
}

void Knapsack::GenerationSubsetThings()
{
	Subset subset(this->sizeThing);
	subset.Generetion();
	this->vectorThings = subset.GetSubset();
}

void Knapsack::GenerationVectorWeights()
{
	srand(time_t(NULL));
	for (int i = 0; i < this->sizeThing; i++)
	{
		this->vectorWeights.push_back(rand() % (this->maxWeigthThing - this->minWeigthThing) + this->minWeigthThing);
	}
}

void Knapsack::GenerationVectorPrice()
{
	srand(time_t(NULL));
	for (int i = 0; i < this->sizeThing; i++)
	{
		this->vectorPrice.push_back(rand() % (this->maxPriceThing - this->minPriceThing) + this->minPriceThing);
	}
}