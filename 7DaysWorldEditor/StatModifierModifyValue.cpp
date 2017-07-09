#include "StatModifierModifyValue.h"

#include "BinaryMemoryReader.h"

void StatModifierModifyValue::readMore(BinaryMemoryReader * const reader) {
	StatModifier::readMore(reader);

	reader->read<float>(&unknownV);
	reader->read<float>(&unknownF);
}

StatModifierModifyValue::StatModifierModifyValue() {}
StatModifierModifyValue::~StatModifierModifyValue() {}