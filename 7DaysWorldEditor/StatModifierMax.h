#pragma once

#include "StatModifier.h"

class BinaryMemoryReader;

class StatModifierMax : public StatModifier {
public:
	float unknownV;
	float unknownF;

	StatModifierMax();
	~StatModifierMax();

private:
	void readMore(BinaryMemoryReader &reader) override;
};