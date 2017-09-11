#include "StatModifierMulValue.h"

#include "BinaryMemoryReader.h"

void StatModifierMulValue::readMore(BinaryMemoryReader &reader) {
	StatModifier::readMore(reader);

	reader.read<float>(unknownV);
	reader.read<float>(unknownF);
}

StatModifierMulValue::StatModifierMulValue() {}
StatModifierMulValue::~StatModifierMulValue() {}