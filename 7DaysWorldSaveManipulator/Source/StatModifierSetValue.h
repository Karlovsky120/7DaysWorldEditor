#pragma once
#include "DllHeader.h"

#include "StatModifier.h"

class BinaryMemoryReader;
class BinaryMemoryWriter;

class SDWSM_API StatModifierSetValue : public StatModifier {
public:
	float unknownV;
	float unknownF;

	StatModifierClassId getType() override;
	void write(BinaryMemoryWriter &writer) const override;

	StatModifierSetValue();
	~StatModifierSetValue();

private:
	int readMore(BinaryMemoryReader &reader) override;
};
