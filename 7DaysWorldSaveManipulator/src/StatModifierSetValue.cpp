#include "StatModifierSetValue.h"

#include "BinaryMemoryReader.h"
#include "BinaryMemoryWriter.h"

StatModifierSetValue::StatModifierSetValue() {}
StatModifierSetValue::~StatModifierSetValue() {}

StatModifierClassId StatModifierSetValue::getType() const {
    return SetValue;
}

void StatModifierSetValue::write(BinaryMemoryWriter &writer) const {
    StatModifier::write(writer);

    writer.write<float>(unknownV);
    writer.write<float>(unknownF);
}

int StatModifierSetValue::readMore(BinaryMemoryReader &reader) {
    StatModifier::readMore(reader);

    reader.read<float>(unknownV);
    reader.read<float>(unknownF);

    return 0;
}
