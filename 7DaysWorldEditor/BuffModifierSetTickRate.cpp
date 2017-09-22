#include "BuffModifierSetTickRate.h"

#include "BinaryMemoryReader.h"
#include "BinaryMemoryWriter.h"

BuffModifierClassId BuffModifierSetTickRate::getType() {
	return SetTickRate;
}

void BuffModifierSetTickRate::write(BinaryMemoryWriter &writer) {
	BuffModifier::write(writer);

	writer.write<float>(tickRate);
}

void BuffModifierSetTickRate::readMore(BinaryMemoryReader &reader) {
	BuffModifier::readMore(reader);

	reader.read<float>(tickRate);
}

BuffModifierSetTickRate::BuffModifierSetTickRate() {}
BuffModifierSetTickRate::~BuffModifierSetTickRate() {}

