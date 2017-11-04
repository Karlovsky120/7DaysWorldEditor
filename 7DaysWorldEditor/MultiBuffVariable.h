#pragma once
#include "SaveVersionCheck.h"

class BinaryMemoryReader;
class BinaryMemoryWriter;

class MultiBuffVariable : public SaveVersionCheck{
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

