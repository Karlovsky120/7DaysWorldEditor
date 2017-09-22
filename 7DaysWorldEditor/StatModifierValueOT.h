#pragma once
#include "StatModifier.h"

class BinaryMemoryReader;

class StatModifierValueOT : public StatModifier {
public:
	float unknownV;
	float unknownF;
	float frequency;
	float unknownL;

	StatModifierClassId getType() override;
	void write(BinaryMemoryWriter &writer) override;

	StatModifierValueOT();
	~StatModifierValueOT();

private:
	void readMore(BinaryMemoryReader &reader) override;
};