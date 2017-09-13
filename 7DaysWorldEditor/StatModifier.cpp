#include "StatModifier.h"

#include "BinaryMemoryReader.h"
#include "StatModifierMax.h"
#include "StatModifierValueOT.h"
#include "StatModifierModifyValue.h"
#include "StatModifierSetValue.h"
#include "StatModifierMulValue.h"

#include <assert.h>

std::shared_ptr<StatModifier> StatModifier::read(BinaryMemoryReader &reader) {
	int statModifierVersion;
	unsigned char enumId;
	reader.read<int>(statModifierVersion);
	reader.read<unsigned char>(enumId);

	std::shared_ptr<StatModifier> modifier = instantiate((StatModifierClassId)enumId);
	modifier->statModifierVersion = statModifierVersion;
	modifier->enumId = enumId;

	modifier->readMore(reader);

	return modifier;
}

std::shared_ptr<StatModifier> StatModifier::instantiate(StatModifierClassId id) {
	switch (id) {
		case StatModifierMaxE:
		return std::make_shared<StatModifierMax>();
		case StatModifierValueOTE:
		return std::make_shared<StatModifierValueOT>();
		case StatModifierModifyValueE:
		return std::make_shared<StatModifierModifyValue>();
		case StatModifierSetValueE:
		return std::make_shared<StatModifierSetValue>();
		case StatModifierMulValueE:
		return std::make_shared<StatModifierMulValue>();
	}

	assert(false);
}

void StatModifier::readMore(BinaryMemoryReader &reader) {
	reader.read<int>(UID);
	reader.read<unsigned short>(fileId);
	reader.read<int>(categoryFlag);
	reader.read<int>(stackCount);
	buffTimer.read(reader);
}

StatModifier::StatModifier() {}
StatModifier::~StatModifier() {}