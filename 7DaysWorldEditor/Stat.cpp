#include "Stat.h"

#include "BinaryMemoryReader.h"
#include "StatModifier.h"

void Stat::read(BinaryMemoryReader &reader, std::map<unsigned short, std::shared_ptr<StatModifier>> &idTable) {
	reader.read<int>(statVersion);
	reader.read<float>(value);
	reader.read<float>(maxModifier);
	reader.read<float>(valueModifier);
	reader.read<float>(baseMax);
	reader.read<float>(originalMax);
	reader.read<float>(originalValue);
	reader.read<bool>(unknownG);

	int statModifierListCount;
	reader.read<int>(statModifierListCount);

	for (int i = 0; i < statModifierListCount; ++i) {
		std::shared_ptr<StatModifier> modifier;
		modifier = StatModifier::read(reader);
		modifier->stat = *this;
		statModifierList.push_back(modifier);
		idTable[modifier->fileId] = modifier;
	}
}

Stat::Stat() {}
Stat::~Stat() {}