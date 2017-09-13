#pragma once
#include "RegionFile.h"

#include "BinaryFileReader.h"
#include "BinaryFileWriter.h"
#include "Chunk.h"

#include "log4cplus\logger.h"
#include "log4cplus\loggingmacros.h"

extern log4cplus::Logger mainLog;

void RegionFile::read(std::string path, const int rX, const int rZ) {

	path = path.append("\\r.").append(std::to_string(rX)).append(".").append(std::to_string(rZ)).append(".7rg");

	BinaryFileReader reader;

	if (reader.open(path)) {

		timeStamps.reserve(1024);
		zippedChunks.reserve(1024);

		for (int i = 0; i < 1024; ++i) {
			reader.seek(4 + 4 * i, std::ios_base::beg);

			unsigned short offset;
			reader.read<unsigned short>(offset);

			if (offset != 0) {
				reader.seek(4100 + 4 * i, std::ios_base::beg);

				int timeStamp;
				reader.read<int>(timeStamp);
				timeStamps.push_back(timeStamp);

				reader.seek(offset * 4096 + 4, std::ios_base::beg);

				int length;
				reader.read<int>(length);

				reader.seek(1, std::ios_base::cur);

				std::vector<unsigned char> chunkData;
				chunkData.resize(length);
				reader.readBytes(&chunkData[0], length);
				zippedChunks.push_back(chunkData);
			}

			else {
				// This chunk hasn't been generated yet.

				// We push zero to the timeStamp.
				timeStamps.push_back(0);

				// We create a vector, resize it to zero and push it to zippedChunks.
				std::vector<unsigned char> chunkData(0);
				zippedChunks.push_back(chunkData);
			}
		}
	} else {
		std::stringstream error;
		error << "Failed to open region file " << rX << "." << rZ << ".7rg @ " << path;
		LOG4CPLUS_ERROR(mainLog, LOG4CPLUS_TEXT(error.str()));
	}
}

void RegionFile::write(std::string path) {
	path = path.append("\\r.").append(std::to_string(rX)).append(".").append(std::to_string(rZ)).append(".7rg");

	BinaryFileWriter writer(path);

	unsigned char ch = 55;
	writer.writeByte(&ch);

	ch = 114;
	writer.writeByte(&ch);

	ch = 103;
	writer.writeByte(&ch);

	writer.seek(4100, std::ios_base::beg);

	for (int i = 0; i < 1024; ++i) {
		writer.writeInt32(&timeStamps[i]);
	}

	std::vector<short> offsets;
	offsets.reserve(1024);
	std::vector<unsigned char> size;
	size.reserve(1024);

	for (int j = 0; j < 1024; ++j) {
		if (zippedChunks[j].size() != 0) {
		#pragma warning(suppress: 4244)
			int position = writer.baseStream.tellp();

			int pA = ((position - 4) / 4096) + 1;
			offsets.push_back(((position - 4) / 4096) + 1);
			writer.baseStream.seekp((offsets[j] * 4096) + 4, std::ios_base::beg);

		#pragma warning(suppress: 4267)
			int chunkSize = zippedChunks[j].size();

			int BB = (chunkSize / 4096) + 1;
			size.push_back((chunkSize / 4096) + 1);

			writer.writeInt32(&chunkSize);
			ch = 0;
			writer.writeByte(&ch);
			writer.writeBytes(&zippedChunks[j][0], chunkSize);

			writer.seek((offsets[j] + size[j]) * 4096, std::ios_base::beg);
		}

		else {
			offsets.push_back(0);
			size.push_back(0);
		}
	}

	writer.seek(4, std::ios_base::beg);

	for (int k = 0; k < 1024; ++k) {
		writer.writeInt16(&offsets[k]);
		writer.writeByte(&ch);
		writer.writeByte(&size[k]);
	}
}

bool RegionFile::chunkExists(const int rcX, const int rcZ) {
	return zippedChunks[rcX + 32 * rcZ].size() > 0;
}

bool RegionFile::getChunk(Chunk &chunk, const int rcX, const int rcZ) {
	std::vector<unsigned char> &zippedChunk = zippedChunks[rcX + 32 * rcZ];

	if (chunkExists(rcX, rcZ)) {
		return chunk.unpackChunk(chunk, zippedChunks[rcX + 32 * rcZ]);
	}

	return false;
}

RegionFile::RegionFile(const std::string path, const int rX, const int rZ) :
	rX(rX),
	rZ(rZ) {

	read(path, rX, rZ);
}

RegionFile::RegionFile() {}
RegionFile::~RegionFile() {}
