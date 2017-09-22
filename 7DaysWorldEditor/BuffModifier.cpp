#include "BuffModifier.h"

#include "BinaryMemoryReader.h"
#include "BinaryMemoryWriter.h"
#include "BuffModifierSetTickRate.h"

BuffModifierClassId BuffModifier::getType() {
	return BuffModifierBase;
}

std::shared_ptr<BuffModifier> BuffModifier::instantiate(BuffModifierClassId id) {
	switch (id) {
		case SetTickRate:
		return std::make_shared<BuffModifierSetTickRate>();
		default:
		return std::make_shared<BuffModifier>();
	}
}

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

void BuffModifier::write(BinaryMemoryWriter &writer) {
	writer.write<int>(buffModifierVersion);
	writer.write<unsigned char>(buffModifierClassId);

	writer.write<int>(gh);
}

void BuffModifier::readMore(BinaryMemoryReader &reader) {
	reader.read<int>(gh);
}

BuffModifier::BuffModifier() {}
BuffModifier::~BuffModifier() {}