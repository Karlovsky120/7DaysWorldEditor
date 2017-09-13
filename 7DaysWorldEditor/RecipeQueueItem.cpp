#include "RecipeQueueItem.h"

#include "BinaryMemoryReader.h"

void RecipeQueueItem::read(BinaryMemoryReader &reader) {
	bool isRecipeNotNull;
	reader.read<bool>(isRecipeNotNull);

	if (isRecipeNotNull) {
		recipe.read(reader);
	}

	reader.read<float>(craftingTimeLeft);
	reader.read<int>(multiplier);
	reader.read<bool>(isCrafting);

	bool isRepairItemNotNull;
	reader.read<bool>(isRepairItemNotNull);

	if (isRepairItemNotNull) {
		repairItem.read(reader);
		reader.read<int>(amountToRepair);
	}

	reader.read<int>(quality);
	reader.read<int>(startingEntityId);
}

RecipeQueueItem::RecipeQueueItem() {}
RecipeQueueItem::~RecipeQueueItem() {}