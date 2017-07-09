#include "ChunkBlockChannel.h"

#include "BinaryMemoryReader.h"

ChunkBlockChannel *ChunkBlockChannel::read(BinaryMemoryReader *const reader) {
	cbcLayer.resize(64);
	jj.resize(64);

	for (int i = 0; i < 64; ++i) {
		bool *flag;
		reader->read<bool>(&flag);

		if (!*flag) {
			reader->readBytes(&cbcLayer[i], 1024);
			jj[i] = nullptr;
		}
		else {
			reader->read<unsigned char>(&jj[i]);
			cbcLayer[i] = nullptr;
		}
	}

	return this;
}

ChunkBlockChannel::ChunkBlockChannel() {}
ChunkBlockChannel::~ChunkBlockChannel() {}