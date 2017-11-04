#pragma once
#include "Buff.h"
#include "MultiBuffVariable.h"
#include "VersionCheck.h"
#include "Stat.h"
#include "StatModifier.h"

#include <map>
#include <memory>
#include <string>
#include <vector>

class BinaryMemoryReader;
class BinaryMemoryWriter;

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

class EntityStats : public VersionCheck {
public:
	int statsVersion;
	int buffCategoryFlags;

	std::vector<int> immunity;
	std::map<unsigned short, std::shared_ptr<StatModifier>> idTable;

	Stat health;
	Stat stamina;
	Stat sickness;
	Stat gassines;
	Stat speedModifier;
	Stat wellness;
	Stat coreTemp;
	Stat food;
	Stat water;

	float waterLevel;

	std::vector<std::shared_ptr<Buff>> buffList;
	std::map<std::string, MultiBuffVariable> multiBuffVariableMap;

	int read(BinaryMemoryReader &reader);
	void write(BinaryMemoryWriter &writer) const ;

	EntityStats();
	~EntityStats();
};

