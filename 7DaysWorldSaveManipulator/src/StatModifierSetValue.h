#pragma once

#include "StatModifier.h"

class BinaryMemoryReader;
class BinaryMemoryWriter;

class StatModifierSetValue : public StatModifier {
public:
	float unknownV;
	float unknownF;

	StatModifierSetValue();
	~StatModifierSetValue();

	StatModifierClassId getType() const override;
	void write(BinaryMemoryWriter &writer) const override;

private:
	int readMore(BinaryMemoryReader &reader) override;
};
