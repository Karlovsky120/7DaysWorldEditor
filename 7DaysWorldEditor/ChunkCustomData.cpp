#include "ChunkCustomData.h"

#include "BinaryMemoryReader.h"

void ChunkCustomData::read(BinaryMemoryReader &reader) {
	reader.readString(&key);
	reader.readUInt64(&expiresInWorldTime);
	reader.readBoolean(&isSavedToNetwork);

	unsigned short *dataLength;
	reader.readUInt16(&dataLength);

	if (*dataLength > 0) {
		reader.readBytes((unsigned char **)&data, *dataLength);
	}
}

ChunkCustomData::ChunkCustomData() {
}


ChunkCustomData::~ChunkCustomData() {
}
