#include "RecipeQueueItem.h"

#include "BinaryMemoryReader.h"
#include "ItemValue.h"
#include "Recipe.h"

RecipeQueueItem *RecipeQueueItem::read(BinaryMemoryReader *const reader) {

	bool *isRecipeNotNull;
	reader->read<bool>(&isRecipeNotNull);
	if (*isRecipeNotNull) {
		recipe = new Recipe();
		recipe->read(reader);
	}

	reader->read<float>(&craftingTimeLeft);
	reader->read<int>(&multiplier);
	reader->read<bool>(&isCrafting);

	bool *isRepairItemNotNull;
	reader->read<bool>(&isRepairItemNotNull);
	if (*isRepairItemNotNull) {
		repairItem = new ItemValue();
		repairItem->read(reader);
		reader->read<int>(&amountToRepair);
	}

	reader->read<int>(&quality);
	reader->read<int>(&startingEntityId);

	return this;
}

RecipeQueueItem::RecipeQueueItem() {}
RecipeQueueItem::~RecipeQueueItem() {}