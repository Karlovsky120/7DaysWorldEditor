#pragma once

#include "StatModifier.h"

class BinaryMemoryReader;

class StatModifierMulValue : public StatModifier
{
public:
	float *unknownV;
	float *unknownF;

	StatModifierMulValue();
	~StatModifierMulValue();

private:
	void readMore(BinaryMemoryReader *const reader) override;
};