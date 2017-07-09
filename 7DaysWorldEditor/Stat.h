#pragma once

#include <map>
#include <vector>

class BinaryMemoryReader;
class StatModifier;

class Stat
{
public:
	int *statVersion;
	float *value;
	float *maxModifier;
	float *valueModifier;
	float *baseMax;
	float *originalMax;
	float *originalValue;
	bool *unknownG;

	std::vector<StatModifier *> statModifierList;

	Stat *read(BinaryMemoryReader *const reader, std::map<unsigned short *, StatModifier *> idTable);

	Stat();
	~Stat();
};

