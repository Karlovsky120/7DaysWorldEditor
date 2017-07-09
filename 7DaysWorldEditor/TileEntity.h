#pragma once

#include "Coordinate.h"

class BinaryMemoryReader;

enum TileEntityType { NoneType , Campfire = 5, Forge, Loot, SecureDoor, SecureLoot, Sign, Trader, VendingMachine, Workstation };

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

