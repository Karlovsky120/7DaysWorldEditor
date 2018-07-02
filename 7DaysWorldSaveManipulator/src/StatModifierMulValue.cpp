#include "StatModifierMulValue.h"

#include "BinaryMemoryReader.h"
#include "BinaryMemoryWriter.h"

StatModifierMulValue::StatModifierMulValue() {}
StatModifierMulValue::~StatModifierMulValue() {}

StatModifierClassId StatModifierMulValue::getType() const {
    return MulValue;
}

void StatModifierMulValue::write(BinaryMemoryWriter &writer) const {
    StatModifier::write(writer);

    writer.write<float>(unknownV);
    writer.write<float>(unknownF);
}

int StatModifierMulValue::readMore(BinaryMemoryReader &reader) {
    StatModifier::readMore(reader);

    reader.read<float>(unknownV);
    reader.read<float>(unknownF);

    return 0;
}
