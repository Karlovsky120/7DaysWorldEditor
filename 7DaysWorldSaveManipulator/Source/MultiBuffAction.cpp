#include "MultiBuffAction.h"

#include "BinaryMemoryReader.h"
#include "BinaryMemoryWriter.h"
#include "VersionCheck.h"

int MultiBuffAction::read(BinaryMemoryReader &reader) {
	reader.read<int>(multiBuffActionVersion);
	VersionCheck::checkVersion(multiBuffActionVersion, MULTI_BUFF_ACTION_VER, MULTI_BUFF_ACTION);

	reader.read<unsigned char>(commandId);
	reader.read<float>(unknownC);
	reader.read<int>(categoryFlags);
	reader.read<int>(unknownV);
	reader.read<std::string>(unknownO);
	reader.read<std::string>(unknownW);
	reader.read<std::string>(context);

	unknownJ = BuffTimer::read(reader);
	unknownS = BuffTimer::read(reader);

	reader.read<bool>(unknownF);
	reader.read<bool>(unknownI);

	return 0;
}

void MultiBuffAction::write(BinaryMemoryWriter &writer) const {
	writer.write<int>(multiBuffActionVersion);
	writer.write<unsigned char>(commandId);
	writer.write<float>(unknownC);
	writer.write<int>(categoryFlags);
	writer.write<int>(unknownV);
	writer.write<std::string>(unknownO);
	writer.write<std::string>(unknownW);
	writer.write<std::string>(context);

	unknownJ->write(writer);
	unknownS->write(writer);

	writer.write<bool>(unknownF);
	writer.write<bool>(unknownI);
}

MultiBuffAction::MultiBuffAction() {}
MultiBuffAction::~MultiBuffAction() {}
