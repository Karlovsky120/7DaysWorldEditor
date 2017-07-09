#include "StatModifier.h"

#include "BinaryMemoryReader.h"
#include "BuffTimer.h"
#include "StatModifierMax.h"
#include "StatModifierValueOT.h"
#include "StatModifierModifyValue.h"
#include "StatModifierSetValue.h"
#include "StatModifierMulValue.h"

StatModifier *StatModifier::read(BinaryMemoryReader * const reader) {
	int *statModifierVersion;
	unsigned char *enumId;
	reader->read<int>(&statModifierVersion);
	reader->read<unsigned char>(&enumId);

	StatModifier *modifier = instantiate((StatModifierClassId)*enumId);
	modifier->statModifierVersion = statModifierVersion;
	modifier->enumId = enumId;

	modifier->readMore(reader);
	return modifier;
}

StatModifier *StatModifier::instantiate(StatModifierClassId id)
{
	switch (id) {
	case StatModifierMaxE:
		return new StatModifierMax();
	case StatModifierValueOTE:
		return new StatModifierValueOT();
	case StatModifierModifyValueE:
		return new StatModifierModifyValue();
	case StatModifierSetValueE:
		return new StatModifierSetValue();
	case StatModifierMulValueE:
		return new StatModifierMulValue();
	}

	return new StatModifier();
}

void StatModifier::readMore(BinaryMemoryReader * const reader) {
	reader->read<int>(&UID);
	reader->read<unsigned short>(&fileId);
	reader->read<int>(&categoryFlag);
	reader->read<int>(&stackCount);
	buffTimer->read(reader);
}

StatModifier::StatModifier() {}
StatModifier::~StatModifier() {}