#pragma once

#include <map>
#include <vector>

class BinaryMemoryReader;
class BuffDescriptor;
class BuffTimer;
class BuffModifier;
class StatModifier;

enum BuffClassId { MultiBuff, Count };

class Buff
{
public:
	unsigned short *buffVersion;
	unsigned char *buffClassId;

	BuffTimer *timer;
	BuffDescriptor *descriptor;
	bool *isOverriden;
	std::vector<StatModifier *> statModifierList;
	std::vector<BuffModifier *> buffModifierList;
	int *instigatorId;

	Buff *read(BinaryMemoryReader *const reader, std::map<unsigned short *, StatModifier *> idTable);
	static Buff *instantiate(BuffClassId type);
	virtual void readMore(BinaryMemoryReader *const reader, std::map<unsigned short *, StatModifier *> idTable);

	Buff();
	~Buff();
};