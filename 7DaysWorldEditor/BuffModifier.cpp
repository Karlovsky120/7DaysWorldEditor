#include "BuffModifier.h"

#include "BinaryMemoryReader.h"
#include "BinaryMemoryWriter.h"
#include "BuffModifierSetTickRate.h"
#include "VersionCheck.h"

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
	VersionCheck::checkVersion(buffModifierVersion, BUFF_MODIFIER_VER, BUFF_MODIFIER);

	unsigned char buffModifierClassId;
	reader.read<unsigned char>(buffModifierClassId);

	std::shared_ptr<BuffModifier> modifier = instantiate((BuffModifierClassId)buffModifierClassId);
	modifier->buffModifierVersion = buffModifierVersion;
	modifier->buffModifierClassId = buffModifierClassId;
	modifier->readMore(reader);

	return modifier;
}

void BuffModifier::write(BinaryMemoryWriter &writer) const {
	writer.write<int>(buffModifierVersion);
	writer.write<unsigned char>(buffModifierClassId);

	writer.write<int>(gh);
}

int BuffModifier::readMore(BinaryMemoryReader &reader) {
	reader.read<int>(gh);
	return 0;
}

BuffModifier::BuffModifier() {}
BuffModifier::~BuffModifier() {}
