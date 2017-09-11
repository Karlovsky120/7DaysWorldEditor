#include "BuffModifierSetTickRate.h"

#include "BinaryMemoryReader.h"

void BuffModifierSetTickRate::readMore(BinaryMemoryReader &reader) {
	BuffModifier::readMore(reader);
	reader.read<float>(tickRate);
}

BuffModifierSetTickRate::BuffModifierSetTickRate() {}
BuffModifierSetTickRate::~BuffModifierSetTickRate() {}

