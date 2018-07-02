#pragma once

#include "ItemStack.h"

#include "VersionCheck.h"

#include <vector>

class BinaryMemoryReader;
class BinaryMemoryWriter;

class TraderData {
public:
    int traderID;
    unsigned _int64 lastInventoryUpdate;
    unsigned char fileVersion;

    std::vector<ItemStack> primaryInventory;
    std::vector<std::vector<ItemStack>> tierItemGroups;

    int availableMoney;
    std::vector<char> jj;

    TraderData();
    ~TraderData();

    int read(BinaryMemoryReader &reader);
    void write(BinaryMemoryWriter &writer) const;
};
