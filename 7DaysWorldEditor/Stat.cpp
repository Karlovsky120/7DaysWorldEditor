#include "Stat.h"

#include "BinaryMemoryReader.h"
#include "BinaryMemoryWriter.h"
#include "StatModifier.h"

int Stat::read(BinaryMemoryReader &reader, std::map<unsigned short, std::shared_ptr<StatModifier>> &idTable) {
	reader.read<int>(statVersion);
	CHECK_VERSION(statVersion, STAT);

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
		int statModifierVersion;
		modifier = StatModifier::read(reader, statModifierVersion);
		CHECK_VERSION_ZERO(statModifierVersion);
		modifier->stat = *this;
		statModifierList.push_back(modifier);
		idTable[modifier->fileId] = modifier;
	}

	return 0;
}

void Stat::write(BinaryMemoryWriter &writer) const {
	writer.write<int>(statVersion);
	writer.write<float>(value);
	writer.write<float>(maxModifier);
	writer.write<float>(valueModifier);
	writer.write<float>(baseMax);
	writer.write<float>(originalMax);
	writer.write<float>(originalValue);
	writer.write<bool>(unknownG);

#pragma warning (suppress: 4267)
	writer.writeConst<int>(statModifierList.size());

	for (int i = 0; i < statModifierList.size(); ++i) {
		statModifierList[i]->write(writer);
	}
}

Stat::Stat() {}
Stat::~Stat() {}