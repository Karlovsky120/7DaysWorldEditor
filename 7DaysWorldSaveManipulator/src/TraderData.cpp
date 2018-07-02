#include "TraderData.h"

#include "BinaryMemoryReader.h"
#include "BinaryMemoryWriter.h"
#include "VersionCheck.h"

TraderData::TraderData() {}
TraderData::~TraderData() {}

int TraderData::read(BinaryMemoryReader &reader) {
    reader.read<int>(traderID);
    reader.read<unsigned _int64>(lastInventoryUpdate);
    reader.read<unsigned char>(fileVersion);

    VersionCheck::checkVersion(fileVersion, TRADER_DATA_VER, TRADER_DATA);

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

    return 0;
}

void TraderData::write(BinaryMemoryWriter &writer) const {
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
