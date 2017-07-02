#pragma once

#include <string>

class BinaryMemoryReader;

class ChunkCustomData {
public:

	std::string *key;
	unsigned _int64 *expiresInWorldTime;
	bool *isSavedToNetwork;

	unsigned char data[];

	void read(BinaryMemoryReader &reader);

	ChunkCustomData();
	~ChunkCustomData();
};

