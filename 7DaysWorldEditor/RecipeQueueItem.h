#pragma once

class BinaryMemoryReader;
class  ItemValue;
class  Recipe;

class RecipeQueueItem
{
public:
	int *amountToRepair;
	float *craftingTimeLeft;
	bool *isCrafting;
	int *multiplier;
	int *quality;
	Recipe *recipe;
	ItemValue *repairItem;
	int *startingEntityId;

	RecipeQueueItem *read(BinaryMemoryReader *const reader);

	RecipeQueueItem();
	~RecipeQueueItem();
};

