#include "ChunkCustomData.h"

#include "BinaryMemoryReader.h"

ChunkCustomData *ChunkCustomData::read(BinaryMemoryReader *const reader) {
	reader->read<std::string>(&key);
	reader->read<unsigned _int64>(&expiresInWorldTime);
	reader->read<bool>(&isSavedToNetwork);

	unsigned short *dataLength;
	reader->read<unsigned short>(&dataLength);

	if (*dataLength > 0) {
		reader->readBytes((unsigned char **)&data, *dataLength);
	}

	return this;
}

ChunkCustomData::ChunkCustomData() {}
ChunkCustomData::~ChunkCustomData() {}
