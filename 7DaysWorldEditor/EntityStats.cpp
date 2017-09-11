#include "EntityStats.h"

#include "BinaryMemoryReader.h"
#include "Buff.h"
#include "MultiBuffVariable.h"
#include "Stat.h"

void EntityStats::read(BinaryMemoryReader &reader) {
	reader.read<int>(statsVersion);
	reader.read<int>(buffCategoryFlags);

	reader.readMultipleSimple<int, int>(immunity);

	health.read(reader, idTable);
	stamina.read(reader, idTable);
	sickness.read(reader, idTable);
	gassines.read(reader, idTable);
	speedModifier.read(reader, idTable);
	wellness.read(reader, idTable);
	coreTemp.read(reader, idTable);
	food.read(reader, idTable);
	water.read(reader, idTable);

	reader.read(waterLevel);

	int buffCount;
	reader.read<int>(buffCount);

	for (int i = 0; i < buffCount; ++i) {
		std::shared_ptr<Buff> buff = Buff::read(reader, idTable);
		buffList.push_back(buff);
	}

	int multiBuffVariableCount;
	reader.read<int>(multiBuffVariableCount);

	for (int j = 0; j < multiBuffVariableCount; ++j) {
		std::string key;
		reader.read<std::string>(key);
		MultiBuffVariable variable;
		variable.read(reader);
		multiBuffVariableMap[key] = variable;
	}
}

EntityStats::EntityStats() {}
EntityStats::~EntityStats() {}