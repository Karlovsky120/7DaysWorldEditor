#pragma once

#include <vector>

class BinaryMemoryReader;

class ChunkBlockLayer
{

public:
	unsigned char *oh;
	unsigned char *jh;
	unsigned char *fh;

	void read(BinaryMemoryReader &reader);

	ChunkBlockLayer();
	~ChunkBlockLayer();
};

