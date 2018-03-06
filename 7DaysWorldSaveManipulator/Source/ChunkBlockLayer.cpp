#include "ChunkBlockLayer.h"

#include "BinaryMemoryReader.h"
#include "BinaryMemoryWriter.h"

void ChunkBlockLayer::read(BinaryMemoryReader &reader) {
	bool flag;
	reader.read<bool>(flag);

	if (flag) {
		oh.first = true;
		reader.readBytes(&oh.second[0], 1024);
		jh.first = false;
	}
	else {
		jh.first = true;
		reader.read<unsigned char>(jh.second);
		oh.first = false;
	}

	bool flag2;
	reader.read<bool>(flag2);

	if (flag2) {
		fh.first = true;
		reader.readBytes(&fh.second[0], 3072);
	}
	else {
		fh.first = false;
	}
}

void ChunkBlockLayer::write(BinaryMemoryWriter &writer) const {
	bool flag = oh.first == true;
	writer.write<bool>(flag);

	if (flag) {
		writer.writeBytes(oh.second, 1024);
	}
	else {
		writer.write<unsigned char>(jh.second);
	}

	bool flag2 = fh.first == true;

	writer.write<bool>(flag2);
	if (flag2) {
		writer.writeBytes(fh.second, 3072);
	}
}

ChunkBlockLayer::ChunkBlockLayer() {}
ChunkBlockLayer::~ChunkBlockLayer() {}
