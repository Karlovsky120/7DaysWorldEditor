#pragma once

#include "StatModifier.h"

class BinaryMemoryReader;

class StatModifierModifyValue : public StatModifier {
public:
    float unknownV;
    float unknownF;

    StatModifierModifyValue();
    ~StatModifierModifyValue();

    StatModifierClassId getType() const override;
    void write(BinaryMemoryWriter &writer) const override;

private:
    int readMore(BinaryMemoryReader &reader) override;
};
