#pragma once
#include "DllHeader.h"

#include "BuffModifier.h"

class BinaryMemoryReader;

class SDWSM_API BuffModifierSetTickRate : public BuffModifier {
public:
	float tickRate;

	BuffModifierClassId getType() override;
	void write(BinaryMemoryWriter &writer) const override;

	BuffModifierSetTickRate();
	~BuffModifierSetTickRate();

protected:
	int readMore(BinaryMemoryReader &reader) override;
};
