#pragma once

#include "BuffTimer.h"

#include <string>

class BinaryMemoryReader;

enum Command {
	Damage,
	Kill,
	Debuff,
	AddImmunity,
	SetStatValue,
	ResetStat,
	AttachPrefab,
	Increment,
	Min,
	Max,
	SetVar,
	Buff
};

class MultiBuffAction {
public:
	int multiBuffActionVersion;
	unsigned char commandId;
	float unknownC;
	int categoryFlags;
	int unknownV;
	std::string unknownO;
	std::string unknownW;
	std::string context;

	BuffTimer unknownJ;
	BuffTimer unknownS;

	bool unknownF;
	bool unknownI;

	void read(BinaryMemoryReader &reader);

	MultiBuffAction();
	~MultiBuffAction();
};

