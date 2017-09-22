#include "StatModifierModifyValue.h"

#include "BinaryMemoryReader.h"
#include "BinaryMemoryWriter.h"

StatModifierClassId StatModifierModifyValue::getType() {
	return ModifyValue;
}

void StatModifierModifyValue::write(BinaryMemoryWriter &writer) {
	StatModifier::write(writer);

	writer.write<float>(unknownV);
	writer.write<float>(unknownF);
}

void StatModifierModifyValue::readMore(BinaryMemoryReader &reader) {
	StatModifier::readMore(reader);

	reader.read<float>(unknownV);
	reader.read<float>(unknownF);
}

StatModifierModifyValue::StatModifierModifyValue() {}
StatModifierModifyValue::~StatModifierModifyValue() {}