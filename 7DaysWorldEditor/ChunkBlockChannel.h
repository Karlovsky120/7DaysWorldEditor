#pragma once

#include <map>

class BinaryMemoryReader;

template <int bytesPerValue = 1>
class ChunkBlockChannel {
public:
	std::map<unsigned int, std::array<unsigned char, bytesPerValue * 1024>> cbcLayer;
	std::map<unsigned int, std::array<unsigned char, bytesPerValue>> jj;

	void read(BinaryMemoryReader &reader) {
		for (int i = 0; i < 64; ++i) {
			bool flag;
			reader.read<bool>(flag);

			if (!flag) {
				std::array<unsigned char, bytesPerValue * 1024> data;
				reader.readBytes(&data[0], bytesPerValue * 1024);
				cbcLayer[i] = data;
			} else {
				std::array<unsigned char, bytesPerValue> data;
				reader.readBytes(&data[0], bytesPerValue);
				jj[i] = data;
			}
		}
	}

	ChunkBlockChannel() {};
	~ChunkBlockChannel() {};
};
