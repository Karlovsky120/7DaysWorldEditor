#pragma once
#include "BuffTimer.h"
#include "VersionCheck.h"
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

class StatModifier : public VersionCheck {
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
	static std::shared_ptr<StatModifier> read(BinaryMemoryReader &reader, int &statModifierVersion);
	virtual void write(BinaryMemoryWriter &writer);

	StatModifier();
	~StatModifier();

protected:
	int virtual readMore(BinaryMemoryReader &reader);
};

