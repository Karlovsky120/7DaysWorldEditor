#include "MultiBuffAction.h"

#include "BinaryMemoryReader.h"
#include "BuffTimer.h"

MultiBuffAction *MultiBuffAction::read(BinaryMemoryReader *const reader) {
	reader->read<int>(&multiBuffActionVersion);
	reader->read<unsigned char>(&commandId);
	reader->read<float>(&unknownC);
	reader->read<int>(&categoryFlags);
	reader->read<int>(&unknownV);
	reader->read<std::string>(&unknownO);
	reader->read<std::string>(&unknownW);
	reader->read<std::string>(&context);

	unknownJ = new BuffTimer();
	unknownJ->read(reader);
	unknownS = new BuffTimer();
	unknownS->read(reader);

	reader->read<bool>(&unknownF);
	reader->read<bool>(&unknownI);

	return this;
}

MultiBuffAction::MultiBuffAction() {}
MultiBuffAction::~MultiBuffAction() {}