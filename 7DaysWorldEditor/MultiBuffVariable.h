#pragma once

class BinaryMemoryReader;

class MultiBuffVariable
{
public:
	int *multiBuffVariableVersion;
	float *unknownQ;
	float *unknownJ;
	float *unknownS;
	float *unknownC;

	MultiBuffVariable *read(BinaryMemoryReader *const reader);

	MultiBuffVariable();
	~MultiBuffVariable();
};

