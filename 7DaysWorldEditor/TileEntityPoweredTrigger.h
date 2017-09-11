#pragma once
#include "TileEntityPowered.h"

#include <string>

class BinaryMemoryReader;

enum TriggerTypes {
	Switch,
	PressurePlateTrigger,
	TimerRelay,
	Motion,
	TripWire
};

class TileEntityPoweredTrigger : public TileEntityPowered {
public:
	unsigned char triggerType;
	std::string lrz;

	bool showTriggerOptions;

	unsigned char property1;
	unsigned char property2;

	int targetType;

	void reader(BinaryMemoryReader &reader);

	TileEntityPoweredTrigger();
	~TileEntityPoweredTrigger();
};