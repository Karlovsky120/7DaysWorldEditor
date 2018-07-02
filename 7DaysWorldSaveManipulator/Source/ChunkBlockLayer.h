#pragma once

#include <utility>
#include <array>

class BinaryMemoryReader;
class BinaryMemoryWriter;

class ChunkBlockLayer {
public:
	std::pair<bool, std::array<unsigned char, 1024>> oh;
	std::pair<bool, unsigned char> jh;
	std::pair<bool, std::array<unsigned char, 3072>> fh;

	void read(BinaryMemoryReader &reader);
	void write(BinaryMemoryWriter &writer) const;

	ChunkBlockLayer();
	~ChunkBlockLayer();
};
