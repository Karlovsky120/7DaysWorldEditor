#pragma once

#include <string>

class BinaryMemoryReader;

class ChunkCustomData {
public:
	std::string *key;
	unsigned _int64 *expiresInWorldTime;
	bool *isSavedToNetwork;

	#pragma warning(suppress: 4200) // Array size determined when being read.
	unsigned char data[];

	ChunkCustomData *read(BinaryMemoryReader *const reader);

	ChunkCustomData();
	~ChunkCustomData();
};

