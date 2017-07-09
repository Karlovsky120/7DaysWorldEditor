#pragma once

#include <string>

class BinaryMemoryReader;
class BuffTimer;

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

class MultiBuffAction
{
public:
	int *multiBuffActionVersion;
	unsigned char *commandId;
	float *unknownC;
	int *categoryFlags;
	int *unknownV;
	std::string *unknownO;
	std::string *unknownW;
	std::string *context;

	BuffTimer *unknownJ;
	BuffTimer *unknownS;

	bool *unknownF;
	bool *unknownI;

	MultiBuffAction *read(BinaryMemoryReader *const reader);

	MultiBuffAction();
	~MultiBuffAction();
};

