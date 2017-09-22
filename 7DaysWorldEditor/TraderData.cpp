#include "TraderData.h"

#include "BinaryMemoryReader.h"
#include "BinaryMemoryWriter.h"

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

void TraderData::write(BinaryMemoryWriter &writer) {
	writer.write<int>(traderID);
	writer.write<unsigned _int64>(lastInventoryUpdate);
	writer.write<unsigned char>(fileVersion);

	writer.writeMultipleComplex<ItemStack, unsigned short>(primaryInventory);

#pragma warning (suppress: 4267)
	writer.writeConst<unsigned char>(tierItemGroups.size());

	for (auto tierItemGroup : tierItemGroups) {
		writer.writeMultipleComplex<ItemStack, unsigned short>(tierItemGroup);
	}

	writer.write<int>(availableMoney);
	writer.writeMultipleSimple<char, int>(jj);
}

TraderData::TraderData() {}
TraderData::~TraderData() {}