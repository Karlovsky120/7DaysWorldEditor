#include "BuffModifier.h"

#include "BinaryMemoryReader.h"
#include "BuffModifierSetTickRate.h"

#include <assert.h>


std::shared_ptr<BuffModifier> BuffModifier::read(BinaryMemoryReader &reader) {
	int buffModifierVersion;
	reader.read<int>(buffModifierVersion);
	unsigned char buffModifierClassId;
	reader.read<unsigned char>(buffModifierClassId);

	std::shared_ptr<BuffModifier> modifier = instantiate((BuffModifierClassId)buffModifierClassId);
	modifier->buffModifierVersion = buffModifierVersion;
	modifier->buffModifierClassId = buffModifierClassId;
	modifier->readMore(reader);

	return modifier;
}

std::shared_ptr<BuffModifier> BuffModifier::instantiate(BuffModifierClassId id) {
	switch (id) {
		case BuffModifierSetTickRateEnum:
		return std::make_shared<BuffModifierSetTickRate>();
	}

	assert(false);
}

void BuffModifier::readMore(BinaryMemoryReader &reader) {
	reader.read<int>(buffModifierVersion);
	reader.read<unsigned char>(buffModifierClassId);
}

BuffModifier::BuffModifier() {}
BuffModifier::~BuffModifier() {}