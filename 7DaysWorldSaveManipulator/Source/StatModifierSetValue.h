#pragma once

#include "StatModifier.h"

class BinaryMemoryReader;
class BinaryMemoryWriter;

class StatModifierSetValue : public StatModifier {
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
