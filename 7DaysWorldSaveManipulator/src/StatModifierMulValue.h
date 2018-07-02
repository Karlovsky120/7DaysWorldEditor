#pragma once

#include "StatModifier.h"

class BinaryMemoryReader;

class StatModifierMulValue : public StatModifier {
public:
    float unknownV;
    float unknownF;

    StatModifierMulValue();
    ~StatModifierMulValue();

    StatModifierClassId getType() const override;
    void write(BinaryMemoryWriter &writer) const override;

private:
    int readMore(BinaryMemoryReader &reader) override;
};
