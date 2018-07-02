#include "TileEntityLootContainer.h"

#include "BinaryMemoryReader.h"
#include "BinaryMemoryWriter.h"

TileEntityLootContainer::TileEntityLootContainer() {}
TileEntityLootContainer::~TileEntityLootContainer() {}

TileEntityClassId TileEntityLootContainer::getType() const {
    return Loot;
}

int TileEntityLootContainer::read(BinaryMemoryReader &reader) {
    TileEntity::read(reader);

    reader.read<unsigned short>(lootListIndex);
    reader.read<unsigned short>(ad.x);
    reader.read<unsigned short>(ad.y);

    reader.read<bool>(bTouched);
    reader.read<unsigned int>(worldTimeTouched);
    reader.read<bool>(bPlayerBackpack);

    short itemsLength;
    reader.read<short>(itemsLength);
    itemsLength = ((((int)itemsLength) < (ad.x * ad.y)) ? itemsLength : (ad.x * ad.y));

    reader.readMultipleComplex<ItemStack, short>(items, itemsLength);
    reader.read<bool>(bPlayerStorage);

    return 0;
}

void TileEntityLootContainer::write(BinaryMemoryWriter &writer) const {
    TileEntity::write(writer);

    writer.write<unsigned short>(lootListIndex);
    writer.write<unsigned short>(ad.x);
    writer.write<unsigned short>(ad.y);

    writer.write<bool>(bTouched);
    writer.write<unsigned int>(worldTimeTouched);
    writer.write<bool>(bPlayerBackpack);

#pragma warning (suppress: 4267)
    short itemsLength = items.size();
    writer.write<short>(itemsLength);

    writer.writeMultipleComplex<ItemStack, short>(items, itemsLength);
    writer.write<bool>(bPlayerStorage);
}
