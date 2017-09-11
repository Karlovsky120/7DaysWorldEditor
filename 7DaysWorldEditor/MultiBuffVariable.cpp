#include "MultiBuffVariable.h"

#include "BinaryMemoryReader.h"

void MultiBuffVariable::read(BinaryMemoryReader &reader) {
	reader.read<int>(multiBuffVariableVersion);
	reader.read<float>(unknownQ);
	reader.read<float>(unknownJ);
	reader.read<float>(unknownS);
	reader.read<float>(unknownC);
}

MultiBuffVariable::MultiBuffVariable() {}
MultiBuffVariable::~MultiBuffVariable() {}