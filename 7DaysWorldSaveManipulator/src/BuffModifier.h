#pragma once

#include "VersionCheck.h"

#include <memory>

class BinaryMemoryReader;
class BinaryMemoryWriter;

enum BuffModifierClassId {
    SetTickRate,
    BuffModifierBase
};

class BuffModifier {
public:
    int gh;
    int buffModifierVersion;
    unsigned char buffModifierClassId;

    BuffModifier();
    ~BuffModifier();

    virtual BuffModifierClassId getType();
    static std::shared_ptr<BuffModifier> instantiate(BuffModifierClassId id);
    static std::shared_ptr<BuffModifier> read(BinaryMemoryReader &reader);
    void virtual write(BinaryMemoryWriter &writer) const;

protected:
    virtual int readMore(BinaryMemoryReader &reader);
};
