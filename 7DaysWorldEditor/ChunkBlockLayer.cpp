#include "ChunkBlockLayer.h"

#include "BinaryMemoryReader.h"

void ChunkBlockLayer::read(BinaryMemoryReader &reader) {
	bool flag;
	reader.read<bool>(flag);

	if (flag) {
		oh.first = true;
		reader.readBytes(&oh.second[0], 1024);
		jh.first = false;
	} else {
		jh.first = true;
		reader.read<unsigned char>(jh.second);
		oh.first = false;
	}

	reader.read<bool>(flag);

	if (flag) {
		fh.first = true;
		reader.readBytes(&fh.second[0], 3072);
	} else {
		fh.first = false;
	}
}

ChunkBlockLayer::ChunkBlockLayer() {}
ChunkBlockLayer::~ChunkBlockLayer() {}
