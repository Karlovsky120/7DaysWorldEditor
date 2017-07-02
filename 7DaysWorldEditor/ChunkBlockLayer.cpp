#include "ChunkBlockLayer.h"

#include "BinaryMemoryReader.h"

void ChunkBlockLayer::read(BinaryMemoryReader &reader) {
	bool *flag;
	reader.readBoolean(&flag);

	if (flag) {
		reader.readBytes(&oh, 1024);
	}
	else {
		jh;
		reader.readByte(&jh);
	}

	bool *flag2;
	reader.readBoolean(&flag2);

	if (flag2) {
		reader.readBytes(&fh, 3072);
	}
}

ChunkBlockLayer::ChunkBlockLayer() {
}


ChunkBlockLayer::~ChunkBlockLayer() {
}
