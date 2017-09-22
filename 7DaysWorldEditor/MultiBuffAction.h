#pragma once
#include "BuffTimer.h"

#include <string>

class BinaryMemoryReader;
class BinaryMemoryWriter;

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
	MaxCommand,
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
	void write(BinaryMemoryWriter &writer) const;

	MultiBuffAction();
	~MultiBuffAction();
};

