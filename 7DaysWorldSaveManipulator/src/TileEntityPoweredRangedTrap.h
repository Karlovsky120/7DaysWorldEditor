#pragma once

#include "TileEntityPoweredBlock.h"

class BinaryMemoryReader;
class BinaryMemoryWriter;
class ItemStack;

class TileEntityPoweredRangedTrap : public TileEntityPoweredBlock {
public:
    std::string lrz;
    bool flag;
    bool isLocked;
    std::vector<ItemStack> itemSlots;
    int targetType;

    TileEntityPoweredRangedTrap();
    ~TileEntityPoweredRangedTrap();

    TileEntityClassId getType() const override;
    int read(BinaryMemoryReader &reader) override;
    void write(BinaryMemoryWriter &writer) const override;
};
