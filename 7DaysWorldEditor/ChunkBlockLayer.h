#pragma once

#include <vector>

class BinaryMemoryReader;

class ChunkBlockLayer
{

public:
	unsigned char oh[1024];
	unsigned char *jh;
	unsigned char fh[3072];

	ChunkBlockLayer *read(BinaryMemoryReader *const reader);

	ChunkBlockLayer();
	~ChunkBlockLayer();
};

