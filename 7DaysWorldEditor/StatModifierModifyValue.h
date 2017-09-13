#pragma once
#include "StatModifier.h"

class BinaryMemoryReader;

class StatModifierModifyValue : public StatModifier {
public:
	float unknownV;
	float unknownF;

	StatModifierModifyValue();
	~StatModifierModifyValue();

private:
	void readMore(BinaryMemoryReader &reader) override;
};