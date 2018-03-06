#pragma once
#include "Coordinate.h"

#include <memory>

class BinaryMemoryReader;
class BinaryMemoryWriter;

enum TileEntityClassId {
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
	Trigger = 19,
	TileEntityBase
};

class TileEntity {
public:
	unsigned short tileEntityVersion;
	Coordinate<int> localChunkPosition;
	int entityId;
	unsigned _int64 worldTimeHeatMapSomething;

	virtual TileEntityClassId getType();
	static std::shared_ptr<TileEntity> instantiate(TileEntityClassId type);
	virtual int read(BinaryMemoryReader &reader);
	virtual void write(BinaryMemoryWriter &writer) const;

	TileEntity();
	~TileEntity();
};
