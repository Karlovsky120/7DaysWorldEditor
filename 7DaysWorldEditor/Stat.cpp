#include "Stat.h"

#include "BinaryMemoryReader.h"
#include "StatModifier.h"

Stat *Stat::read(BinaryMemoryReader *const reader, std::map<unsigned short *, StatModifier *> idTable) {
	reader->read<int>(&statVersion);
	reader->read<float>(&value);
	reader->read<float>(&maxModifier);
	reader->read<float>(&valueModifier);
	reader->read<float>(&baseMax);
	reader->read<float>(&originalMax);
	reader->read<float>(&originalValue);
	reader->read<bool>(&unknownG);

	int *statModifierListCount;
	reader->read<int>(&statModifierListCount);

	for (int i = 0; i < *statModifierListCount; ++i) {
		StatModifier *modifier = new StatModifier();
		modifier->stat = this;
		statModifierList.push_back(modifier);
		idTable[modifier->fileId] = modifier;
	}

	return this;
}

Stat::Stat() {}
Stat::~Stat() {}