#include "ChunkCustomData.h"

#include "BinaryMemoryReader.h"
#include "BinaryMemoryWriter.h"

int ChunkCustomData::read(BinaryMemoryReader &reader) {
	reader.read<std::string>(key);
	reader.read<unsigned _int64>(expiresInWorldTime);
	reader.read<bool>(isSavedToNetwork);

	unsigned short dataLength;
	reader.read<unsigned short>(dataLength);

	if (dataLength > 0) {
		reader.readBytes(data, dataLength);
	}

	return 0;
}

void ChunkCustomData::write(BinaryMemoryWriter &writer) const {
	writer.write<std::string>(key);
	writer.write<unsigned _int64>(expiresInWorldTime);
	writer.write<bool>(isSavedToNetwork);

#pragma warning (suppress: 4267)
	writer.writeConst<unsigned short>(data.size());

	if (data.size() > 0) {
#pragma warning (suppress: 4267)
		unsigned short dataLength = data.size();
		writer.writeBytes(data, dataLength);
	}
}

ChunkCustomData::ChunkCustomData() {}
ChunkCustomData::~ChunkCustomData() {}
