#include "Buff.h"

#include "BinaryMemoryReader.h"
#include "BinaryMemoryWriter.h"
#include "MultiBuff.h"
#include "VersionCheck.h"


Buff::Buff() {}
Buff::~Buff() {}

BuffClassId Buff::getType() {
    return BuffBase;
}

std::shared_ptr<Buff> Buff::instantiate(BuffClassId type) {
    switch (type) {
        case MultiBuffType:
            return std::make_shared<MultiBuff>();
        case Count:
            //BuffCount doesn't exist, but it was still in the enum, sooo...
        default:
            return std::make_shared<Buff>();
    }
}

std::shared_ptr<Buff> Buff::read(BinaryMemoryReader &reader, std::map<unsigned short, std::shared_ptr<StatModifier>> idTable) {
    unsigned short buffVersion;
    reader.read<unsigned short>(buffVersion);
    VersionCheck::checkVersion(buffVersion, BUFF_VER, BUFF);

    unsigned char buffClassId;
    reader.read<unsigned char>(buffClassId);

    std::shared_ptr<Buff> buff = instantiate((BuffClassId)buffClassId);
    buff->buffVersion = buffVersion;
    buff->buffClassId = buffClassId;

    buff->readMore(reader, idTable);

    return buff;
}

void Buff::write(BinaryMemoryWriter &writer, std::map<unsigned short, std::shared_ptr<StatModifier>> idTable) const {
    writer.write<unsigned short>(buffVersion);
    writer.write<unsigned char>(buffClassId);

    timer->write(writer);
    descriptor.write(writer);
    writer.write<bool>(isOverriden);

#pragma warning (suppress: 4267)
    writer.writeConst<unsigned char>(statModifierList.size());

    for (auto it = idTable.begin(); it != idTable.end(); ++it) {
        unsigned short first = it->first;
        writer.write<unsigned short>(first);
    }

#pragma warning (suppress: 4267)
    writer.writeConst<unsigned char>(buffModifierList.size());

    for (auto &buffModifier : buffModifierList) {
        buffModifier->write(writer);
    }

    writer.write<int>(instigatorId);
}

int Buff::readMore(BinaryMemoryReader &reader, std::map<unsigned short, std::shared_ptr<StatModifier>> idTable) {
    timer = BuffTimer::read(reader);
    descriptor.read(reader);
    reader.read<bool>(isOverriden);

    unsigned char statModifierCount;
    reader.read<unsigned char>(statModifierCount);

    for (int i = 0; i < statModifierCount; ++i) {
        unsigned short key;
        reader.read<unsigned short>(key);

        std::shared_ptr<StatModifier> statModifier = idTable[key];
        statModifierList.push_back(statModifier);
    }

    unsigned char buffModifierCount;
    reader.read<unsigned char>(buffModifierCount);

    for (int j = 0; j < buffModifierCount; ++j) {
        std::shared_ptr<BuffModifier> modifier;
        modifier = BuffModifier::read(reader);
        buffModifierList.push_back(modifier);
    }

    reader.read<int>(instigatorId);

    return 0;
}
