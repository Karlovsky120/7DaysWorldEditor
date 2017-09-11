#pragma once

#include "ItemValue.h"
#include "Recipe.h"

class BinaryMemoryReader;

class RecipeQueueItem
{
public:
	int amountToRepair;
	float craftingTimeLeft;
	bool isCrafting;
	int multiplier;
	int quality;
	Recipe recipe;
	ItemValue repairItem;
	int startingEntityId;

	void read(BinaryMemoryReader &reader);

	RecipeQueueItem();
	~RecipeQueueItem();
};

