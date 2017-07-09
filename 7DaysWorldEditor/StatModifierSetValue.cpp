#include "StatModifierSetValue.h"

#include "BinaryMemoryReader.h"

void StatModifierSetValue::readMore(BinaryMemoryReader * const reader) {
	StatModifier::readMore(reader);

	reader->read<float>(&unknownV);
	reader->read<float>(&unknownF);
}

StatModifierSetValue::StatModifierSetValue() {}
StatModifierSetValue::~StatModifierSetValue() {}
