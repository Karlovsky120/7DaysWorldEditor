#pragma once

#include "BuffTimer.h"
#include "Stat.h"


class BinaryMemoryReader;

enum BuffCategoryFlag;

enum StatModifierClassId {
	StatModifierMaxE,
	StatModifierValueOTE,
	StatModifierModifyValueE,
	StatModifierSetValueE,
	StatModifierMulValueE
};

class StatModifier {
public:
	int statModifierVersion;
	unsigned char enumId;

	int UID;
	unsigned short fileId;
	int categoryFlag;
	int stackCount;

	BuffTimer buffTimer;
	Stat stat;

	static std::shared_ptr<StatModifier> read(BinaryMemoryReader &reader);
	static std::shared_ptr<StatModifier> instantiate(StatModifierClassId id);

	StatModifier();
	~StatModifier();

protected:
	void virtual readMore(BinaryMemoryReader &reader);

};

