#include "StatModifierValueOT.h"

#include "BinaryMemoryReader.h"
#include "BinaryMemoryWriter.h"

StatModifierClassId StatModifierValueOT::getType() {
	return ValueOT;
}

void StatModifierValueOT::write(BinaryMemoryWriter &writer) const {
	StatModifier::write(writer);

	writer.write<float>(unknownV);
	writer.write<float>(unknownF);
	writer.write<float>(frequency);
	writer.write<float>(unknownL);
}

int StatModifierValueOT::readMore(BinaryMemoryReader &reader) {
	StatModifier::readMore(reader);

	reader.read<float>(unknownV);
	reader.read<float>(unknownF);
	reader.read<float>(frequency);
	reader.read<float>(unknownL);

	return 0;
}

StatModifierValueOT::StatModifierValueOT() {}
StatModifierValueOT::~StatModifierValueOT() {}
