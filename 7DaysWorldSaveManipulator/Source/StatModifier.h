#pragma once
#include "DllHeader.h"

#include "BuffTimer.h"
#include "Stat.h"

#include <memory>

class BinaryMemoryReader;

enum BuffCategoryFlag;

enum StatModifierClassId {
	Max,
	ValueOT,
	ModifyValue,
	SetValue,
	MulValue,
	StatModifierBase
};

class SDWSM_API StatModifier {
public:
	int statModifierVersion;
	unsigned char enumId;

	int UID;
	unsigned short fileId;
	int categoryFlag;
	int stackCount;

	BuffTimer buffTimer;
	Stat stat;

	virtual StatModifierClassId getType();
	static std::shared_ptr<StatModifier> instantiate(StatModifierClassId id);
	static std::shared_ptr<StatModifier> read(BinaryMemoryReader &reader);
	virtual void write(BinaryMemoryWriter &writer) const;

	StatModifier();
	~StatModifier();

protected:
	int virtual readMore(BinaryMemoryReader &reader);
};
