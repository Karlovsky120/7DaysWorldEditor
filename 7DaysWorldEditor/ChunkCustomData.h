#pragma once
#include <string>
#include <vector>

class BinaryMemoryReader;

class ChunkCustomData {
public:
	std::string key;
	unsigned _int64 expiresInWorldTime;
	bool isSavedToNetwork;

	std::vector<unsigned char> data;

	void read(BinaryMemoryReader &reader);

	ChunkCustomData();
	~ChunkCustomData();
};

