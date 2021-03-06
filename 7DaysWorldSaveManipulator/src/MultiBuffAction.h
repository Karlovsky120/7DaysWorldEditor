#pragma once

#include "BuffTimer.h"

#include <string>
#include <memory>

class BinaryMemoryReader;
class BinaryMemoryWriter;

enum Command {
    Damage,
    Kill,
    Debuff,
    AddImmunity,
    SetStatValue,
    ResetStat,
    AttachPrefab,
    Increment,
    Min,
    MaxCommand,
    SetVar,
    BuffEnum
};

class MultiBuffAction {
public:
    int multiBuffActionVersion;
    unsigned char commandId;
    float unknownC;
    int categoryFlags;
    int unknownV;
    std::string unknownO;
    std::string unknownW;
    std::string context;

    std::shared_ptr<BuffTimer> unknownJ;
    std::shared_ptr<BuffTimer> unknownS;

    bool unknownF;
    bool unknownI;

    MultiBuffAction();
    ~MultiBuffAction();

    int read(BinaryMemoryReader &reader);
    void write(BinaryMemoryWriter &writer) const;
};
