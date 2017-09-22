#pragma once
#include "ItemValue.h"
#include "Recipe.h"

class BinaryMemoryReader;
class BinaryMemoryWriter;

class RecipeQueueItem {
public:
	int amountToRepair;
	float craftingTimeLeft;
	bool isCrafting;
	int multiplier;
	int quality;
	std::pair<bool, Recipe> recipe;
	std::pair<bool, ItemValue> repairItem;
	int startingEntityId;

	void read(BinaryMemoryReader &reader);
	void write(BinaryMemoryWriter &writer) const;

	RecipeQueueItem();
	~RecipeQueueItem();
};

