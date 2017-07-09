#pragma once

#include <vector>

class BinaryMemoryReader;
class CBCLayer;

class ChunkBlockChannel
{
public:
	std::vector<unsigned char *> cbcLayer;
	std::vector<unsigned char *> jj;

	ChunkBlockChannel *read(BinaryMemoryReader *const reader);

	ChunkBlockChannel();
	~ChunkBlockChannel();
};
