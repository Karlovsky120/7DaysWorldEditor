#pragma once

#include "Coordinate.h"

#include <memory>

class BinaryMemoryReader;

enum TileEntityType {
	NoneType,
	Loot = 5,
	Trader,
	VendingMachine,
	Forge,
	Campfire,
	SecureLoot,
	SecureDoor,
	Workstation,
	Sign,
	GoreBlock,
	Powered,
	PowerSource,
	PowerRangeTrap,
	Trigger = 19
};

class TileEntity {
public:
	unsigned short tileEntityVersion;
	Coordinate<int> localChunkPosition;
	int entityId;
	unsigned _int64 worldTimeHeatMapSomething;

	virtual void read(BinaryMemoryReader &reader);
	static std::shared_ptr<TileEntity> instantiate(TileEntityType type);

	TileEntity();
	~TileEntity();
};

