#include "StatModifierModifyValue.h"

#include "BinaryMemoryReader.h"
#include "BinaryMemoryWriter.h"

StatModifierModifyValue::StatModifierModifyValue() {}
StatModifierModifyValue::~StatModifierModifyValue() {}

StatModifierClassId StatModifierModifyValue::getType() const {
    return ModifyValue;
}

void StatModifierModifyValue::write(BinaryMemoryWriter &writer) const {
    StatModifier::write(writer);

    writer.write<float>(unknownV);
    writer.write<float>(unknownF);
}

int StatModifierModifyValue::readMore(BinaryMemoryReader &reader) {
    StatModifier::readMore(reader);

    reader.read<float>(unknownV);
    reader.read<float>(unknownF);

    return 0;
}

