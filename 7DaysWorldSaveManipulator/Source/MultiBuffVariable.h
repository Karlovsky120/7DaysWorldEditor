#pragma once
#include "DllHeader.h"

#include "VersionCheck.h"

class BinaryMemoryReader;
class BinaryMemoryWriter;

class SDWSM_API MultiBuffVariable {
public:
	int multiBuffVariableVersion;
	float unknownQ;
	float unknownJ;
	float unknownS;
	float unknownC;

	int read(BinaryMemoryReader &reader);
	void write(BinaryMemoryWriter &writer) const;

	MultiBuffVariable();
	~MultiBuffVariable();
};
