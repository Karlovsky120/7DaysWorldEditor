#pragma once

#include <map>

#include "BinaryMemoryReader.h"
#include "BinaryMemoryWriter.h"

template <int bytesPerValue = 1>
class ChunkBlockChannel {
public:
	std::map<unsigned int, std::array<unsigned char, bytesPerValue * 1024>> cbcLayer;
	std::map<unsigned int, std::array<unsigned char, bytesPerValue>> jj;

	int read(BinaryMemoryReader &reader) {
		for (int i = 0; i < 64; ++i) {
			bool flag;
			reader.read<bool>(flag);

			if (flag) {
				std::array<unsigned char, bytesPerValue> data;
				reader.readBytes(&data[0], bytesPerValue);
				jj[i] = data;
			}
			else {
				std::array<unsigned char, bytesPerValue * 1024> data;
				reader.readBytes(&data[0], bytesPerValue * 1024);
				cbcLayer[i] = data;
			}
		}

		return 0;
	}

	void write(BinaryMemoryWriter &writer) const {
		for (int i = 0; i < 64; ++i) {
			bool flag = jj.find(i) != jj.end();
			writer.write(flag);
			if (flag) {
				writer.writeBytes(jj.find(i)->second, bytesPerValue);
			}
			else {
				writer.writeBytes(cbcLayer.find(i)->second, bytesPerValue * 1024);
			}
		}
	}

	ChunkBlockChannel() {};
	~ChunkBlockChannel() {};
};
