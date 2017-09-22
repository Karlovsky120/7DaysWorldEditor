#pragma once
#include "StatModifier.h"

class BinaryMemoryReader;

class StatModifierModifyValue : public StatModifier {
public:
	float unknownV;
	float unknownF;

	StatModifierClassId getType() override;
	void write(BinaryMemoryWriter &writer) override;

	StatModifierModifyValue();
	~StatModifierModifyValue();

private:
	void readMore(BinaryMemoryReader &reader) override;
};