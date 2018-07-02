#pragma once

#include "StatModifier.h"

class BinaryMemoryReader;

class StatModifierModifyValue : public StatModifier {
public:
	float unknownV;
	float unknownF;

	StatModifierClassId getType() override;
	void write(BinaryMemoryWriter &writer) const override;

	StatModifierModifyValue();
	~StatModifierModifyValue();

private:
	int readMore(BinaryMemoryReader &reader) override;
};
