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

TileEntity *TileEntity::read(BinaryMemoryReader *const reader)
{
	reader->read<unsigned short>(&tileEntityVersion);
	reader->read<int>(&localChunkPosition.x);
	reader->read<int>(&localChunkPosition.y);
	reader->read<int>(&localChunkPosition.z);

	reader->read<int>(&entityId);

	reader->read<unsigned _int64>(&worldTimeHeatMapSomething);

	return this;
}

TileEntity *TileEntity::instantiate(TileEntityType type)
{
	switch (type) {
	case Campfire:
		return new TileEntityCampfire();
	case Forge:
		return new TileEntityForge();
	case Loot:
		return new TileEntityLootContainer();
	case SecureDoor:
		return new TileEntitySecureDoor();
	case SecureLoot:
		return new TileEntitySecureLootContainer();
	case Sign:
		return new TileEntitySign();
	case Trader:
		return new TileEntityTrader();
	case VendingMachine:
		return new TileEntityVendingMachine();
	case Workstation:
		return new TileEntityWorkstation();
	}

	return new TileEntity();
}

TileEntity::TileEntity(){}
TileEntity::~TileEntity(){}
