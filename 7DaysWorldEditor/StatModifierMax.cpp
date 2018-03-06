#include "StatModifierMax.h"

#include "BinaryMemoryReader.h"
#include "BinaryMemoryWriter.h"

StatModifierClassId StatModifierMax::getType() {
	return Max;
}

void StatModifierMax::write(BinaryMemoryWriter &writer) const {
	StatModifier::write(writer);

	writer.write<float>(unknownV);
	writer.write<float>(unknownF);
}

int StatModifierMax::readMore(BinaryMemoryReader &reader) {
	StatModifier::readMore(reader);

	reader.read<float>(unknownV);
	reader.read<float>(unknownF);

	return 0;
}

StatModifierMax::StatModifierMax() {}
StatModifierMax::~StatModifierMax() {}
