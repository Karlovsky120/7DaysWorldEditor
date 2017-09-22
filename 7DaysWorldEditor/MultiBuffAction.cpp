#include "MultiBuffAction.h"

#include "BinaryMemoryReader.h"
#include "BinaryMemoryWriter.h"

void MultiBuffAction::read(BinaryMemoryReader &reader) {
	reader.read<int>(multiBuffActionVersion);
	reader.read<unsigned char>(commandId);
	reader.read<float>(unknownC);
	reader.read<int>(categoryFlags);
	reader.read<int>(unknownV);
	reader.read<std::string>(unknownO);
	reader.read<std::string>(unknownW);
	reader.read<std::string>(context);

	unknownJ.read(reader);
	unknownS.read(reader);

	reader.read<bool>(unknownF);
	reader.read<bool>(unknownI);
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

	unknownJ.write(writer);
	unknownS.write(writer);

	writer.write<bool>(unknownF);
	writer.write<bool>(unknownI);
}

MultiBuffAction::MultiBuffAction() {}
MultiBuffAction::~MultiBuffAction() {}