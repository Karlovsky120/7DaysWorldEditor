#pragma once
#include "StatModifier.h"

class BinaryMemoryReader;

class StatModifierMulValue : public StatModifier {
public:
	float unknownV;
	float unknownF;

	StatModifierClassId getType() override;
	void write(BinaryMemoryWriter &writer) override;

	StatModifierMulValue();
	~StatModifierMulValue();

private:
	int readMore(BinaryMemoryReader &reader) override;
};