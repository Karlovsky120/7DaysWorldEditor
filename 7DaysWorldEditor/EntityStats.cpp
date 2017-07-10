#include "EntityStats.h"

#include "BinaryMemoryReader.h"
#include "Buff.h"
#include "MultiBuffVariable.h"
#include "Stat.h"

EntityStats *EntityStats::read(BinaryMemoryReader * const reader)
{
	reader->read<int>(&statsVersion);
	reader->read<int>(&buffCategoryFlags);

	reader->readMultipleSimple<int, int>(immunity);

	health = new Stat();
	health->read(reader, idTable);
	stamina = new Stat();
	stamina->read(reader, idTable);
	sickness = new Stat();
	sickness->read(reader, idTable);
	gassines = new Stat();
	gassines->read(reader, idTable);
	speedModifier = new Stat();
	speedModifier->read(reader, idTable);
	wellness = new Stat();
	wellness->read(reader, idTable);
	coreTemp = new Stat();
	coreTemp->read(reader, idTable);
	food = new Stat();
	food->read(reader, idTable);
	water = new Stat();
	water->read(reader, idTable);

	reader->read(&waterLevel);

	int *buffCount;
	reader->read<int>(&buffCount);
	for (int i = 0; i < *buffCount; ++i) {
		Buff *buff = new Buff();
		buff->read(reader, idTable);
		buffList.push_back(buff);
	}

	int *multiBuffVariableCount;
	reader->read<int>(&multiBuffVariableCount);
	for (int j = 0; j < *multiBuffVariableCount; ++j) {
		std::string *key;
		reader->read<std::string>(&key);
		MultiBuffVariable *variable = new MultiBuffVariable();
		multiBuffVariableMap[key] = variable->read(reader);
	}

	return this;
}

EntityStats::EntityStats() {}
EntityStats::~EntityStats() {}