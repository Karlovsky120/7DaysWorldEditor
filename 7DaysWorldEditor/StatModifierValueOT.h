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

private:
	void readMore(BinaryMemoryReader &reader) override;
};