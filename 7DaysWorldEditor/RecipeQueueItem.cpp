#include "RecipeQueueItem.h"

#include "BinaryMemoryReader.h"
#include "BinaryMemoryWriter.h"
#include "VersionCheck.h"

int RecipeQueueItem::read(BinaryMemoryReader &reader) {
	reader.read<bool>(recipe.first);

	if (recipe.first) {
		recipe.second.read(reader);
	}

	reader.read<float>(craftingTimeLeft);
	reader.read<int>(multiplier);
	reader.read<bool>(isCrafting);

	reader.read<bool>(repairItem.first);

	if (repairItem.first) {
		repairItem.second.read(reader);
		reader.read<int>(amountToRepair);
	}

	reader.read<int>(quality);
	reader.read<int>(startingEntityId);

	return 0;
}

void RecipeQueueItem::write(BinaryMemoryWriter &writer) const {
	writer.write<bool>(recipe.first);

	if (recipe.first) {
		recipe.second.write(writer);
	}

	writer.write<float>(craftingTimeLeft);
	writer.write<int>(multiplier);
	writer.write<bool>(isCrafting);

	writer.write<bool>(repairItem.first);

	if (repairItem.first) {
		repairItem.second.write(writer);
		writer.write<int>(amountToRepair);
	}

	writer.write<int>(quality);
	writer.write<int>(startingEntityId);
}

RecipeQueueItem::RecipeQueueItem() {}
RecipeQueueItem::~RecipeQueueItem() {}
