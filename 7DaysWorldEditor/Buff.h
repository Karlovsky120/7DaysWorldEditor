#pragma once
#include "BuffDescriptor.h"
#include "BuffModifier.h"
#include "BuffTimer.h"
#include "StatModifier.h"

#include <map>
#include <vector>

class BinaryMemoryReader;

enum BuffClassId {
	MultiBuffType,
	Count
};

class Buff {
public:
	unsigned short buffVersion;
	unsigned char buffClassId;

	std::shared_ptr<BuffTimer> timer;
	BuffDescriptor descriptor;
	bool isOverriden;
	std::vector<std::shared_ptr<StatModifier>> statModifierList;
	std::vector<BuffModifier> buffModifierList;
	int instigatorId;

	static std::shared_ptr<Buff> instantiate(BuffClassId type);
	static std::shared_ptr<Buff> read(BinaryMemoryReader &reader, std::map<unsigned short, std::shared_ptr<StatModifier>> idTable);

	Buff();
	~Buff();

protected:
	virtual void readMore(BinaryMemoryReader &reader, std::map<unsigned short, std::shared_ptr<StatModifier>> idTable);
};