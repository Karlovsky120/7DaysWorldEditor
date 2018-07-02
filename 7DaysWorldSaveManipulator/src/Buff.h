#pragma once

#include "BuffDescriptor.h"
#include "BuffModifier.h"
#include "BuffTimer.h"
#include "StatModifier.h"

#include <map>
#include <vector>

class BinaryMemoryReader;
class BinaryMemoryWriter;

enum BuffClassId {
    MultiBuffType,
    Count,
    BuffBase
};

class Buff {
public:
    unsigned short buffVersion;
    unsigned char buffClassId;
    std::shared_ptr<BuffTimer> timer;
    BuffDescriptor descriptor;
    bool isOverriden;
    std::vector<std::shared_ptr<StatModifier>> statModifierList;
    std::vector<std::shared_ptr<BuffModifier>> buffModifierList;
    int instigatorId;


    Buff();
    virtual ~Buff();


    virtual BuffClassId getType();
    static std::shared_ptr<Buff> instantiate(BuffClassId type);
    static std::shared_ptr<Buff> read(BinaryMemoryReader &reader, std::map<unsigned short, std::shared_ptr<StatModifier>> idTable);
    virtual void write(BinaryMemoryWriter &writer, std::map<unsigned short, std::shared_ptr<StatModifier>> idTable) const;

protected:
    virtual int readMore(BinaryMemoryReader &reader, std::map<unsigned short, std::shared_ptr<StatModifier>> idTable);
};
