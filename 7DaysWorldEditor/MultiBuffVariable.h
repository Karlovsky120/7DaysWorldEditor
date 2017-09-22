#pragma once
class BinaryMemoryReader;
class BinaryMemoryWriter;

class MultiBuffVariable {
public:
	int multiBuffVariableVersion;
	float unknownQ;
	float unknownJ;
	float unknownS;
	float unknownC;

	void read(BinaryMemoryReader &reader);
	void write(BinaryMemoryWriter &writer) const;

	MultiBuffVariable();
	~MultiBuffVariable();
};

