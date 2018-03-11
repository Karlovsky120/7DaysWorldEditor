#pragma once
#include "DllHeader.h"

#include "StatModifier.h"

class BinaryMemoryReader;

class SDWSM_API StatModifierMulValue : public StatModifier {
public:
	float unknownV;
	float unknownF;

	StatModifierClassId getType() override;
	void write(BinaryMemoryWriter &writer) const override;

	StatModifierMulValue();
	~StatModifierMulValue();

private:
	int readMore(BinaryMemoryReader &reader) override;
};
