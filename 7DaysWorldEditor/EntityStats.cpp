#include "EntityStats.h"

#include "BinaryMemoryReader.h"
#include "BinaryMemoryWriter.h"

int EntityStats::read(BinaryMemoryReader &reader) {
	reader.read<int>(statsVersion);
	CHECK_VERSION(statsVersion, ENTITY_STATS);

	reader.read<int>(buffCategoryFlags);

	reader.readMultipleSimple<int, int>(immunity);

	CHECK_VERSION_ZERO((health.read(reader, idTable)));
	CHECK_VERSION_ZERO((stamina.read(reader, idTable)));
	CHECK_VERSION_ZERO((sickness.read(reader, idTable)));
	CHECK_VERSION_ZERO((gassines.read(reader, idTable)));
	CHECK_VERSION_ZERO((speedModifier.read(reader, idTable)));
	CHECK_VERSION_ZERO((wellness.read(reader, idTable)));
	CHECK_VERSION_ZERO((coreTemp.read(reader, idTable)));
	CHECK_VERSION_ZERO((food.read(reader, idTable)));
	CHECK_VERSION_ZERO((water.read(reader, idTable)));

	reader.read<float>(waterLevel);

	int buffCount;
	reader.read<int>(buffCount);

	for (int i = 0; i < buffCount; ++i) {
		int buffVersion;
		std::shared_ptr<Buff> buff = Buff::read(reader, idTable, buffVersion);
		CHECK_VERSION_ZERO(buffVersion);

		buffList.push_back(buff);
	}

	int multiBuffVariableCount;
	reader.read<int>(multiBuffVariableCount);

	for (int j = 0; j < multiBuffVariableCount; ++j) {
		std::string key;
		reader.read<std::string>(key);
		MultiBuffVariable variable;
		CHECK_VERSION_ZERO(variable.read(reader));
		multiBuffVariableMap[key] = variable;
	}

	return 0;
}

void EntityStats::write(BinaryMemoryWriter &writer) const {
	writer.write<int>(statsVersion);
	writer.write<int>(buffCategoryFlags);

	writer.writeMultipleSimple<int, int>(immunity);

	health.write(writer);
	stamina.write(writer);
	sickness.write(writer);
	gassines.write(writer);
	speedModifier.write(writer);
	wellness.write(writer);
	coreTemp.write(writer);
	food.write(writer);
	water.write(writer);

	writer.write<float>(waterLevel);

#pragma warning (suppress: 4267)
	writer.writeConst<int>(buffList.size());
	for (int i = 0; i < buffList.size(); ++i) {
		buffList[i]->write(writer, idTable);
	}

#pragma warning (suppress: 4267)
	writer.writeConst<int>(multiBuffVariableMap.size());
	for (auto it = multiBuffVariableMap.begin(); it != multiBuffVariableMap.end(); ++it) {
		std::string first = it->first;
		writer.write<std::string>(first);
		it->second.write(writer);
	}
}

EntityStats::EntityStats() {}
EntityStats::~EntityStats() {}