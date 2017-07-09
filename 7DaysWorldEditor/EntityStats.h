#pragma once

#include <map>
#include <string>
#include <vector>

class BinaryMemoryReader;
class Buff;
class MultiBuffVariable;
class Stat;
class StatModifier;

enum BuffCategoryFlags {
	None = 0,
	Sickness = 1,
	Disease = 2,
	ArmorUp = 4,
	ArmorDown = 8,
	StaminaUp = 16,
	StaminaDown = 32,
	HealthUp = 64,
	HealthDown = 128,
	SpeedModifier = 256,
	Bleeding = 512,
	Drowning = 1024,
	Wellness = 2048,
	CoreTemp = 4096,
	Armor = 12,
	Stamina = 48,
	Health = 192
};

class EntityStats
{
public:
	int *statsVersion;
	BuffCategoryFlags *buffCategoryFlags;

	std::vector<int *> immunity;
	std::map<unsigned short *, StatModifier *> idTable;

	Stat *health;
	Stat *stamina;
	Stat *sickness;
	Stat *gassines;
	Stat *speedModifier;
	Stat *wellness;
	Stat *coreTemp;
	Stat *food;
	Stat *water;

	float *waterLevel;


	std::map<std::string *, MultiBuffVariable *> multiBuffVariableDictionary;
	std::vector<Buff *> buffList;


	EntityStats *read(BinaryMemoryReader *const reader);

	EntityStats();
	~EntityStats();
};

