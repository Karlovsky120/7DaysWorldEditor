#include "StatModifierValueOT.h"

#include "BinaryMemoryReader.h"

void StatModifierValueOT::readMore(BinaryMemoryReader &reader) {
	StatModifier::readMore(reader);

	reader.read<float>(unknownV);
	reader.read<float>(unknownF);
	reader.read<float>(frequency);
	reader.read<float>(unknownL);
}

StatModifierValueOT::StatModifierValueOT() {}
StatModifierValueOT::~StatModifierValueOT() {}