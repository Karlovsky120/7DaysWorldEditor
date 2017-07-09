#include "TraderData.h"

#include "BinaryMemoryReader.h"

TraderData *TraderData::read(BinaryMemoryReader *const reader)
{
	reader->read<int>(&traderID);
	reader->read<unsigned _int64>(&lastInventoryUpdate);
	reader->read<unsigned char>(&fileVersion);

	primaryInventory = ItemStack::readItemStack(reader);

	unsigned char *tierItemGroupCount;
	reader->read<unsigned char>(&tierItemGroupCount);
	
	for (int i = 0; i < *tierItemGroupCount; ++i) {
		std::vector<ItemStack *> *tierItemGroup;
		tierItemGroup = ItemStack::readItemStack(reader);
		tierItemGroups.push_back(tierItemGroup);
	}

	reader->read<int>(&availableMoney);
	reader->readMultipleSimple<char, int>(jj);

	return this;
}

TraderData::TraderData() {}
TraderData::~TraderData() {}