#include "Buff.h"

#include "BinaryMemoryReader.h"
#include "BuffDescriptor.h"
#include "BuffModifier.h"
#include "BuffTimer.h"
#include "MultiBuff.h"
#include "StatModifier.h"

#include <assert.h>

std::shared_ptr<Buff> Buff::read(BinaryMemoryReader &reader, std::map<unsigned short, std::shared_ptr<StatModifier>> idTable) {
	unsigned short buffVersion;
	reader.read<unsigned short>(buffVersion);
	unsigned char buffClassId;
	reader.read<unsigned char>(buffClassId);

	std::shared_ptr<Buff> buff = instantiate((BuffClassId)buffClassId);
	buff->buffVersion = buffVersion;
	buff->buffClassId = buffClassId;

	buff->readMore(reader, idTable);

	return buff;
}

std::shared_ptr<Buff> Buff::instantiate(BuffClassId type) {
	switch (type) {
		case MultiBuffType:
		    return std::make_shared<MultiBuff>();
		case Count:
		    assert(false);
	}
	assert(false);
}

void Buff::readMore(BinaryMemoryReader &reader, std::map<unsigned short, std::shared_ptr<StatModifier>> idTable) {
	timer = BuffTimer::read(reader);
	descriptor.read(reader);
	reader.read<bool>(isOverriden);

	unsigned char statModifierCount;
	reader.read<unsigned char>(statModifierCount);

	for (int i = 0; i < statModifierCount; ++i) {
		unsigned short key;
		reader.read(key);

		std::shared_ptr<StatModifier> statModifier = idTable[key];
		statModifierList.push_back(statModifier);
	}

	unsigned char buffModifierCount;
	reader.read<unsigned char>(buffModifierCount);

	for (int j = 0; j < buffModifierCount; ++j) {
		BuffModifier modifier;
		modifier.read(reader);
		buffModifierList.push_back(modifier);
	}

	reader.read<int>(instigatorId);
}

Buff::Buff() {}
Buff::~Buff() {}