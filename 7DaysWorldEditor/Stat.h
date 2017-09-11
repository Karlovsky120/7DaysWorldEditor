#pragma once

#include <map>
#include <memory>
#include <vector>

class BinaryMemoryReader;
class StatModifier;

class Stat
{
public:
	int statVersion;
	float value;
	float maxModifier;
	float valueModifier;
	float baseMax;
	float originalMax;
	float originalValue;
	bool unknownG;

	std::vector<std::shared_ptr<StatModifier>> statModifierList;

	void read(BinaryMemoryReader &reader, std::map<unsigned short, std::shared_ptr<StatModifier>> &idTable);

	Stat();
	~Stat();
};

