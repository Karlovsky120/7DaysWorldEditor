#include "BuffModifierSetTickRate.h"

#include "BinaryMemoryReader.h"
#include "BinaryMemoryWriter.h"

BuffModifierSetTickRate::BuffModifierSetTickRate() {}
BuffModifierSetTickRate::~BuffModifierSetTickRate() {}

BuffModifierClassId BuffModifierSetTickRate::getType() {
    return SetTickRate;
}

void BuffModifierSetTickRate::write(BinaryMemoryWriter &writer) const {
    BuffModifier::write(writer);

    writer.write<float>(tickRate);
}

int BuffModifierSetTickRate::readMore(BinaryMemoryReader &reader) {
    BuffModifier::readMore(reader);

    reader.read<float>(tickRate);

    return 0;
}
