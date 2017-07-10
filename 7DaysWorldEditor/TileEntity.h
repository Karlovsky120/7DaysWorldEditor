#pragma once

#include "Coordinate.h"

class BinaryMemoryReader;

enum TileEntityType { NoneType , Loot = 5, Trader, VendingMachine, Forge, Campfire, SecureLoot, SecureDoor, Workstation, Sign };

class TileEntity
{
public:
	unsigned short *tileEntityVersion;
	Coordinate<int> localChunkPosition;
	int *entityId;
	unsigned _int64 *worldTimeHeatMapSomething;

	virtual TileEntity *read(BinaryMemoryReader *const reader);
	static TileEntity *instantiate(TileEntityType type);

	TileEntity();
	~TileEntity();
};

