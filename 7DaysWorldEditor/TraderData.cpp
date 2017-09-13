#include "TraderData.h"

#include "BinaryMemoryReader.h"

void TraderData::read(BinaryMemoryReader &reader) {
	reader.read<int>(traderID);
	reader.read<unsigned _int64>(lastInventoryUpdate);
	reader.read<unsigned char>(fileVersion);

	reader.readMultipleComplex<ItemStack, unsigned short>(primaryInventory);

	unsigned char tierItemGroupCount;
	reader.read<unsigned char>(tierItemGroupCount);
	
	for (int i = 0; i < tierItemGroupCount; ++i) {
		std::vector<ItemStack> tierItemGroup;
		reader.readMultipleComplex<ItemStack, unsigned short>(tierItemGroup);
		tierItemGroups.push_back(tierItemGroup);
	}

	reader.read<int>(availableMoney);
	reader.readMultipleSimple<char, int>(jj);
}

TraderData::TraderData() {}
TraderData::~TraderData() {}