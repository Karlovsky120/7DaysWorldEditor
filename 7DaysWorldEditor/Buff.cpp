#include "Buff.h"

#include "BinaryMemoryReader.h"
#include "BuffDescriptor.h"
#include "BuffModifier.h"
#include "BuffTimer.h"

Buff * Buff::read(BinaryMemoryReader * const reader, std::map<unsigned short *, StatModifier *> idTable) {
	unsigned short *buffVersion;
	reader->read<unsigned short>(&buffVersion);
	unsigned char *buffClassId;
	reader->read<unsigned char>(&buffClassId);

	Buff *buff = Buff::instantiate((BuffClassId)*buffClassId);
	buff->buffVersion = buffVersion;
	buff->buffClassId = buffClassId;

	buff->readMore(reader, idTable);
	return buff;
}

Buff *Buff::instantiate(BuffClassId type) {
	return nullptr;
}

void Buff::readMore(BinaryMemoryReader *const reader, std::map<unsigned short *, StatModifier *> idTable) {
	timer = new BuffTimer();
	timer->read(reader);
	descriptor = new BuffDescriptor();
	descriptor->read(reader);
	reader->read<bool>(&isOverriden);

	unsigned char *statModifierCount;
	reader->read<unsigned char>(&statModifierCount);
	for (int i = 0; i < *statModifierCount; ++i) {
		unsigned short* key;
		reader->read(&key);

		StatModifier *statModifier = idTable[key];
		statModifierList.push_back(statModifier);
	}

	unsigned char *buffModifierCount;
	reader->read<unsigned char>(&buffModifierCount);
	for (int j = 0; j < *buffModifierCount; ++j) {
		BuffModifier *modifier = new BuffModifier();
		//modifier->read(reader);
		//modifier->buff = this;
		buffModifierList.push_back(modifier);
	}

	reader->read<int>(&instigatorId);
}

Buff::Buff() {}
Buff::~Buff() {}