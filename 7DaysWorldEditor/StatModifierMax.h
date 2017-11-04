#pragma once
#include "StatModifier.h"

class BinaryMemoryReader;
class BinaryMemoryWriter;

class StatModifierMax : public StatModifier {
public:
	float unknownV;
	float unknownF;

	StatModifierClassId getType() override;
	void write(BinaryMemoryWriter &writer) override;

	StatModifierMax();
	~StatModifierMax();

private:
	int readMore(BinaryMemoryReader &reader) override;
};