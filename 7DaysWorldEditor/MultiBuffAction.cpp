#include "MultiBuffAction.h"

#include "BinaryMemoryReader.h"

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

MultiBuffAction::MultiBuffAction() {}
MultiBuffAction::~MultiBuffAction() {}