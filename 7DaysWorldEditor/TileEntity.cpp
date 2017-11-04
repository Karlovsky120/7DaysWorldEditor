#include "TileEntity.h"

#include "BinaryMemoryReader.h"
#include "BinaryMemoryWriter.h"
#include "TileEntityCampfire.h"
#include "TileEntityForge.h"
#include "TileEntityLootContainer.h"
#include "TileEntitySecureDoor.h"
#include "TileEntitySecureLootContainer.h"
#include "TileEntitySign.h"
#include "TileEntityTrader.h"
#include "TileEntityVendingMachine.h"
#include "TileEntityWorkstation.h"
#include "TileEntityGoreBlock.h"
#include "TileEntityPoweredBlock.h"
#include "TileEntityPowerSource.h"
#include "TileEntityPoweredRangedTrap.h"
#include "TileEntityPoweredTrigger.h"


TileEntityClassId TileEntity::getType() {
	return TileEntityBase;
}

std::shared_ptr<TileEntity> TileEntity::instantiate(TileEntityClassId type) {
	switch (type) {
		case Loot:
		return std::make_shared<TileEntityLootContainer>();
		case Trader:
		return std::make_shared<TileEntityTrader>();
		case VendingMachine:
		return std::make_shared<TileEntityVendingMachine>();
		case Forge:
		return std::make_shared<TileEntityForge>();
		case Campfire:
		return std::make_shared<TileEntityCampfire>();
		case SecureLoot:
		return std::make_shared<TileEntitySecureLootContainer>();
		case SecureDoor:
		return std::make_shared<TileEntitySecureDoor>();
		case Workstation:
		return std::make_shared<TileEntityWorkstation>();
		case Sign:
		return std::make_shared<TileEntitySign>();
		case GoreBlock:
		return std::make_shared<TileEntityGoreBlock>();
		case Powered:
		return std::make_shared<TileEntityPoweredBlock>();
		case PowerSource:
		return std::make_shared<TileEntityPowerSource>();
		case PowerRangeTrap:
		return std::make_shared<TileEntityPoweredRangedTrap>();
		case Trigger:
		return std::make_shared<TileEntityPoweredTrigger>();
		default:
		return std::make_shared<TileEntity>();
	}
}

int TileEntity::read(BinaryMemoryReader &reader) {
	reader.read<unsigned short>(tileEntityVersion);
	CHECK_VERSION(tileEntityVersion, TILE_ENTITY);

	reader.read<int>(localChunkPosition.x);
	reader.read<int>(localChunkPosition.y);
	reader.read<int>(localChunkPosition.z);

	reader.read<int>(entityId);

	reader.read<unsigned _int64>(worldTimeHeatMapSomething);

	return 0;
}

void TileEntity::write(BinaryMemoryWriter &writer) {
	writer.write<unsigned short>(tileEntityVersion);

	writer.write<int>(localChunkPosition.x);
	writer.write<int>(localChunkPosition.y);
	writer.write<int>(localChunkPosition.z);

	writer.write<int>(entityId);

	writer.write<unsigned _int64>(worldTimeHeatMapSomething);
}

TileEntity::TileEntity(){}
TileEntity::~TileEntity(){}
