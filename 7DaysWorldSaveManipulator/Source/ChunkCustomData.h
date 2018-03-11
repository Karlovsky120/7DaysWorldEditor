#pragma once
#include "DllHeader.h"

#include <string>
#include <vector>

class BinaryMemoryReader;
class BinaryMemoryWriter;

class SDWSM_API ChunkCustomData {
public:
	std::string key;
	unsigned _int64 expiresInWorldTime;
	bool isSavedToNetwork;

	std::vector<unsigned char> data;

	int read(BinaryMemoryReader &reader);
	void write(BinaryMemoryWriter &writer) const;

	ChunkCustomData();
	~ChunkCustomData();
};
