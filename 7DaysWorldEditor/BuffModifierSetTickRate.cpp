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

int BuffModifierSetTickRate::readMore(BinaryMemoryReader &reader) {
	CHECK_VERSION_ZERO(BuffModifier::readMore(reader));

	reader.read<float>(tickRate);

	return 0;
}

BuffModifierSetTickRate::BuffModifierSetTickRate() {}
BuffModifierSetTickRate::~BuffModifierSetTickRate() {}

