#include "ChunkCustomData.h"

#include "BinaryMemoryReader.h"

void ChunkCustomData::read(BinaryMemoryReader &reader) {
	reader.read<std::string>(key);
	reader.read<unsigned _int64>(expiresInWorldTime);
	reader.read<bool>(isSavedToNetwork);

	unsigned short dataLength;
	reader.read<unsigned short>(dataLength);

	if (dataLength > 0) {
		reader.readBytes(data, dataLength);
	}
}

ChunkCustomData::ChunkCustomData() {}
ChunkCustomData::~ChunkCustomData() {}
