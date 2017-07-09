#include "ChunkBlockLayer.h"

#include "BinaryMemoryReader.h"

ChunkBlockLayer *ChunkBlockLayer::read(BinaryMemoryReader *const reader) {

	ChunkBlockLayer *chunkBlockLayer = new ChunkBlockLayer();

	bool *flag;
	reader->read<bool>(&flag);

	if (*flag) {
		reader->readBytes((unsigned char**)&chunkBlockLayer->oh, 1024);
	} else {
		reader->read<unsigned char>(&chunkBlockLayer->jh);
	}

	bool *flag2;
	reader->read<bool>(&flag2);

	if (*flag2) {
		reader->readBytes((unsigned char**)&chunkBlockLayer->fh, 3072);
	}

	return this;
}

ChunkBlockLayer::ChunkBlockLayer() {}
ChunkBlockLayer::~ChunkBlockLayer() {}
