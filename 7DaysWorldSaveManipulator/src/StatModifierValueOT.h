#pragma once

#include "StatModifier.h"

class BinaryMemoryReader;

class StatModifierValueOT : public StatModifier {
public:
    float unknownV;
    float unknownF;
    float frequency;
    float unknownL;

    StatModifierValueOT();
    ~StatModifierValueOT();

    StatModifierClassId getType() const override;
    void write(BinaryMemoryWriter &writer) const override;

private:
    int readMore(BinaryMemoryReader &reader) override;
};
