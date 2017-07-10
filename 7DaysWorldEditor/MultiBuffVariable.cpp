#include "MultiBuffVariable.h"

#include "BinaryMemoryReader.h"

MultiBuffVariable * MultiBuffVariable::read(BinaryMemoryReader * const reader) {
	reader->read<int>(&multiBuffVariableVersion);
	reader->read<float>(&unknownQ);
	reader->read<float>(&unknownJ);
	reader->read<float>(&unknownS);
	reader->read<float>(&unknownC);

	return this;
}

MultiBuffVariable::MultiBuffVariable() {}
MultiBuffVariable::~MultiBuffVariable() {}