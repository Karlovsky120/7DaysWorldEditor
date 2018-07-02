#include "StatModifier.h"

#include "BinaryMemoryReader.h"
#include "BinaryMemoryWriter.h"
#include "StatModifierMax.h"
#include "StatModifierValueOT.h"
#include "StatModifierModifyValue.h"
#include "StatModifierSetValue.h"
#include "StatModifierMulValue.h"
#include "VersionCheck.h"

StatModifier::StatModifier() {}
StatModifier::~StatModifier() {}

StatModifierClassId StatModifier::getType() const {
    return StatModifierBase;
}

std::shared_ptr<StatModifier> StatModifier::instantiate(StatModifierClassId id) {
    switch (id) {
        case Max:
            return std::make_shared<StatModifierMax>();
        case ValueOT:
            return std::make_shared<StatModifierValueOT>();
        case ModifyValue:
            return std::make_shared<StatModifierModifyValue>();
        case SetValue:
            return std::make_shared<StatModifierSetValue>();
        case MulValue:
            return std::make_shared<StatModifierMulValue>();
        default:
            return std::make_shared<StatModifier>();
    }
}

std::shared_ptr<StatModifier> StatModifier::read(BinaryMemoryReader &reader) {
    int statModifierVersion;
    unsigned char enumId;
    reader.read<int>(statModifierVersion);
    VersionCheck::checkVersion(statModifierVersion, STAT_MODIFIER_VER, STAT_MODIFIER);

    reader.read<unsigned char>(enumId);

    std::shared_ptr<StatModifier> modifier = instantiate((StatModifierClassId)enumId);
    modifier->statModifierVersion = statModifierVersion;
    modifier->enumId = enumId;

    modifier->readMore(reader);

    return modifier;
}

void StatModifier::write(BinaryMemoryWriter &writer) const {
    writer.write<int>(statModifierVersion);
    writer.write<unsigned char>(enumId);

    writer.write<int>(UID);
    writer.write<unsigned short>(fileId);
    writer.write<int>(categoryFlag);
    writer.write<int>(stackCount);
    buffTimer.write(writer);
}

int StatModifier::readMore(BinaryMemoryReader &reader) {
    reader.read<int>(UID);
    reader.read<unsigned short>(fileId);
    reader.read<int>(categoryFlag);
    reader.read<int>(stackCount);
    buffTimer.read(reader);
    return 0;
}
