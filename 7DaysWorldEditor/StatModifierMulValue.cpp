#include "StatModifierMulValue.h"

#include "BinaryMemoryReader.h"
#include "BinaryMemoryWriter.h"

StatModifierClassId StatModifierMulValue::getType() {
	return MulValue;
}

void StatModifierMulValue::write(BinaryMemoryWriter &writer) {
	StatModifier::write(writer);

	writer.write<float>(unknownV);
	writer.write<float>(unknownF);
}

void StatModifierMulValue::readMore(BinaryMemoryReader &reader) {
	StatModifier::readMore(reader);

	reader.read<float>(unknownV);
	reader.read<float>(unknownF);
}

StatModifierMulValue::StatModifierMulValue() {}
StatModifierMulValue::~StatModifierMulValue() {}