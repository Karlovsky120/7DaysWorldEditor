#include "StatModifierMax.h"

#include "BinaryMemoryReader.h"

void StatModifierMax::readMore(BinaryMemoryReader &reader) {
	StatModifier::readMore(reader);

	reader.read<float>(unknownV);
	reader.read<float>(unknownF);
}

StatModifierMax::StatModifierMax() {}
StatModifierMax::~StatModifierMax() {}