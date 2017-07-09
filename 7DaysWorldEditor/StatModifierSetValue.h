#pragma once

#include "StatModifier.h"

class BinaryMemoryReader;

class StatModifierSetValue : public StatModifier
{
public:
	float *unknownV;
	float *unknownF;

	StatModifierSetValue();
	~StatModifierSetValue();

private:
	void readMore(BinaryMemoryReader *const reader) override;
};