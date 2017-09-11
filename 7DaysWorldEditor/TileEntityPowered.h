#pragma once

#include "TileEntity.h"

#include "Coordinate.h"

#include <vector>

class BinaryMemoryReader;

enum PowerItemTypes {
	None,
	Consumer,
	ConsumerToggle,
	TriggerType,
	Timer,
	Generator,
	SolarPanel,
	BatteryBank,
	RangedTrap,
	ElectricWireRelay,
	TripWireRelay,
	PressurePlate
};

class TileEntityPowered : public TileEntity
{
public:
	int tileEntityPoweredVersion;
	bool isPlayerPlaced;
	unsigned char powerItemType;

	std::vector<Coordinate<int>> intVectors;
	Coordinate<int> kzz;

	float centeredPitch;
	float centeredYaw;

	void read(BinaryMemoryReader &reader);

	TileEntityPowered();
	~TileEntityPowered();
};

