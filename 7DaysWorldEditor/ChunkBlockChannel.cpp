#include "ChunkBlockChannel.h"

#include "BinaryMemoryReader.h"
#include "CBCLayer.h"

void ChunkBlockChannel::read(BinaryMemoryReader &reader) {

	cbcLayer.resize(64);
	jj.resize(64);

	for (int i = 0; i < 64; ++i) {
		bool *flag;
		reader.readBoolean(&flag);

		if (!flag) {
			reader.readBytes(&cbcLayer[i], 1024);
			jj[i] = nullptr;
		}
		else {
			reader.readByte(&jj[i]);
			cbcLayer[i] = nullptr;
		}
	}
}

ChunkBlockChannel::ChunkBlockChannel()
{
}


ChunkBlockChannel::~ChunkBlockChannel()
{
}
