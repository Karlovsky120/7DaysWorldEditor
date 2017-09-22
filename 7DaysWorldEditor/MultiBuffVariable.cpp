#include "MultiBuffVariable.h"

#include "BinaryMemoryReader.h"
#include "BinaryMemoryWriter.h"

void MultiBuffVariable::read(BinaryMemoryReader &reader) {
	reader.read<int>(multiBuffVariableVersion);
	reader.read<float>(unknownQ);
	reader.read<float>(unknownJ);
	reader.read<float>(unknownS);
	reader.read<float>(unknownC);
}

void MultiBuffVariable::write(BinaryMemoryWriter &writer) const {
	writer.write<int>(multiBuffVariableVersion);
	writer.write<float>(unknownQ);
	writer.write<float>(unknownJ);
	writer.write<float>(unknownS);
	writer.write<float>(unknownC);
}

MultiBuffVariable::MultiBuffVariable() {}
MultiBuffVariable::~MultiBuffVariable() {}