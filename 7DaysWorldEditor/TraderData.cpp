#include "TraderData.h"

#include "BinaryMemoryReader.h"
#include "BinaryMemoryWriter.h"

int TraderData::read(BinaryMemoryReader &reader) {
	reader.read<int>(traderID);
	reader.read<unsigned _int64>(lastInventoryUpdate);
	reader.read<unsigned char>(fileVersion);

	CHECK_VERSION(fileVersion, TRADER_DATA);

	CHECK_VERSION_ZERO((reader.readMultipleComplex<ItemStack, unsigned short>(primaryInventory, NO_VERSION)));

	unsigned char tierItemGroupCount;
	reader.read<unsigned char>(tierItemGroupCount);
	
	for (int i = 0; i < tierItemGroupCount; ++i) {
		std::vector<ItemStack> tierItemGroup;
		CHECK_VERSION_ZERO((reader.readMultipleComplex<ItemStack, unsigned short>(tierItemGroup, NO_VERSION)));
		tierItemGroups.push_back(tierItemGroup);
	}

	reader.read<int>(availableMoney);
	reader.readMultipleSimple<char, int>(jj);

	return 0;
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