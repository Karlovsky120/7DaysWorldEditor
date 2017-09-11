#include "TileEntity.h"

#include "BinaryMemoryReader.h"
#include "TileEntityCampfire.h"
#include "TileEntityForge.h"
#include "TileEntityLootContainer.h"
#include "TileEntitySecureDoor.h"
#include "TileEntitySecureLootContainer.h"
#include "TileEntitySign.h"
#include "TileEntityTrader.h"
#include "TileEntityVendingMachine.h"
#include "TileEntityWorkstation.h"

#include <assert.h>

void TileEntity::read(BinaryMemoryReader &reader) {
	reader.read<unsigned short>(tileEntityVersion);

	reader.read<int>(localChunkPosition.x);
	reader.read<int>(localChunkPosition.y);
	reader.read<int>(localChunkPosition.z);

	reader.read<int>(entityId);

	reader.read<unsigned _int64>(worldTimeHeatMapSomething);
}

std::shared_ptr<TileEntity> TileEntity::instantiate(TileEntityType type) {
	switch (type) {
	case Campfire:
		return std::make_shared<TileEntityCampfire>();
	case Forge:
		return std::make_shared<TileEntityForge>();
	case Loot:
		return std::make_shared<TileEntityLootContainer>();
	case SecureDoor:
		return std::make_shared<TileEntitySecureDoor>();
	case SecureLoot:
		return std::make_shared<TileEntitySecureLootContainer>();
	case Sign:
		return std::make_shared<TileEntitySign>();
	case Trader:
		return std::make_shared<TileEntityTrader>();
	case VendingMachine:
		return std::make_shared<TileEntityVendingMachine>();
	case Workstation:
		return std::make_shared<TileEntityWorkstation>();
	}

	assert(false);
}

TileEntity::TileEntity(){}
TileEntity::~TileEntity(){}
