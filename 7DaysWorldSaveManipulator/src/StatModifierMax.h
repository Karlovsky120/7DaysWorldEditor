#pragma once

#include "StatModifier.h"

class BinaryMemoryReader;
class BinaryMemoryWriter;

class StatModifierMax : public StatModifier {
public:
    float unknownV;
    float unknownF;

    StatModifierMax();
    ~StatModifierMax();

    StatModifierClassId getType() const override;
    void write(BinaryMemoryWriter &writer) const override;

private:
    int readMore(BinaryMemoryReader &reader) override;
};
