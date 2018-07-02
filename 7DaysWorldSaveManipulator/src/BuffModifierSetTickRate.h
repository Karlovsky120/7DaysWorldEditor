#pragma once

#include "BuffModifier.h"

class BinaryMemoryReader;

class BuffModifierSetTickRate : public BuffModifier {
public:
	float tickRate;

	BuffModifierClassId getType() override;
	void write(BinaryMemoryWriter &writer) const override;

	BuffModifierSetTickRate();
	~BuffModifierSetTickRate();

protected:
	int readMore(BinaryMemoryReader &reader) override;
};
