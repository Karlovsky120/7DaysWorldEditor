#pragma once

class BinaryMemoryReader;
class BuffTimer;
class Stat;

enum BuffCategoryFlag;

enum StatModifierClassId {
	StatModifierMaxE,
	StatModifierValueOTE,
	StatModifierModifyValueE,
	StatModifierSetValueE,
	StatModifierMulValueE
};

class StatModifier
{
public:
	int *statModifierVersion;
	unsigned char *enumId;

	int *UID;
	unsigned short *fileId;
	int *categoryFlag;
	int *stackCount;
	BuffTimer *buffTimer;

	Stat *stat;

	StatModifier *read(BinaryMemoryReader *const reader);
	static StatModifier *instantiate(StatModifierClassId id);

	StatModifier();
	~StatModifier();

private:
	void virtual readMore(BinaryMemoryReader *const reader);

};

