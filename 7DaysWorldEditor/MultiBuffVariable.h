#pragma once
class BinaryMemoryReader;

class MultiBuffVariable {
public:
	int multiBuffVariableVersion;
	float unknownQ;
	float unknownJ;
	float unknownS;
	float unknownC;

	void read(BinaryMemoryReader &reader);

	MultiBuffVariable();
	~MultiBuffVariable();
};

