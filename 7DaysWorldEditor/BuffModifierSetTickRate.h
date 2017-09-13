#pragma once
#include "BuffModifier.h"

class BinaryMemoryReader;

class BuffModifierSetTickRate : public BuffModifier {
public:
	float tickRate;

	BuffModifierSetTickRate();
	~BuffModifierSetTickRate();

protected:
	void readMore(BinaryMemoryReader &reader) override;
};

