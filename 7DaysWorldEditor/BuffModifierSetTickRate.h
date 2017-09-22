#pragma once
#include "BuffModifier.h"

class BinaryMemoryReader;

class BuffModifierSetTickRate : public BuffModifier {
public:
	float tickRate;

	BuffModifierClassId getType() override;
	void write(BinaryMemoryWriter &writer) override;

	BuffModifierSetTickRate();
	~BuffModifierSetTickRate();

protected:
	void readMore(BinaryMemoryReader &reader) override;
};

