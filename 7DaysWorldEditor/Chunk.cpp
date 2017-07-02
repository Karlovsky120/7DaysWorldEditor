#pragma once

#include "Chunk.h"

#include "BinaryMemoryReader.h"
#include "ChunkBlockLayer.h"
#include "ChunkCustomData.h"
#include "EntityCreationData.h"

#include "Unzip.h"
#include "Zip.h"

#include <log4cplus/logger.h>
#include <log4cplus/loggingmacros.h>

#include <fstream>

bool Chunk::unzipChunk(std::vector<unsigned char> &zipped, std::vector<unsigned char> &unzipped) {

	std::fstream bin("D:\\bin.zip", std::ios::out | std::ios::binary);
	bin.write((char *)&zipped[8], zipped.capacity() - 8);
	bin.close();

	// Those 8 bytes are metadata we no longer need.
	HZIP hz = OpenZip(&zipped[8], zipped.capacity() - 8, 0);

	ZIPENTRY ze;
	ZRESULT result = GetZipItem(hz, 0, &ze);

	log4cplus::Logger logger = log4cplus::Logger::getInstance(LOG4CPLUS_TEXT("main"));

	if (result != ZR_OK) {
		LOG4CPLUS_ERROR(logger, LOG4CPLUS_TEXT("Failed to open zip file within the region file."));

		CloseZip(hz);
		return false;
	}

	result = UnzipItem(hz, 0, &unzipped[0], unzipped.size());
	CloseZip(hz);

	if (result == ZR_OK) {
		unzipped.resize(ze.unc_size);

		std::fstream bin("D:\\bin.unzip", std::ios::out | std::ios::binary);
		bin.write((char *)&unzipped[0], unzipped.capacity());
		bin.close();
	}

	else {
		LOG4CPLUS_ERROR(logger, LOG4CPLUS_TEXT("Failed to unzip zip file within the region file."));
	}

	return result == ZR_OK;
	

	/*std::vector<unsigned char> outBuffer2(1024 * 1024);

	HZIP hz2 = CreateZip(&outBuffer2[0], 1024 * 1024, 0);
	result = ZipAdd(hz2, ze.name, &output[0], ze.unc_size);
	result = GetZipItem(hz2, 0, &ze);


	void** array;
	array = (void**)malloc(10000 * sizeof(void*));

	unsigned long length;

	ZipGetMemory(hz2, array, &length);

	CloseZip(hz2);

	std::fstream bin2("D:\\bin2.zip", std::ios::out | std::ios::binary);
	bin2.write((char *)&outBuffer2[0], length);
	bin2.close();*/
}

bool Chunk::readChunk(Chunk &chunk, std::vector<unsigned char> &unzipped) {
	memoryStart = (int)&unzipped[0];
	memoryEnd = (int)&unzipped[unzipped.size()-1];

	BinaryMemoryReader reader(unzipped);

	reader.readInt32(&xm);
	reader.readInt32(&mm);
	reader.readInt32(&rm);

	reader.readUInt64(&savedInWorldTicks);

	cbl.resize(64);

	for (int i = 0; i < 64; ++i) {
		bool *flag;
		reader.readBoolean(&flag);

		if (*flag) {
			cbl[i].read(reader);
		}
	}

	cbc.read(reader);

	reader.readBytes((unsigned char**)&im[0], 256);
	reader.readBytes((unsigned char**)&terrainHeight[0], 256);
	reader.readBytes((unsigned char**)&biomeID[0], 256);
	reader.readBytes((unsigned char**)&biomeIntentsity[0], 1536);

	reader.readByte(&dominantBiome);
	reader.readByte(&areaMasterDominantBiome);

	unsigned short *customDataCount;
	reader.readUInt16(&customDataCount);

	for (int j = 0; j < *customDataCount; ++j) {
		ChunkCustomData *customData;
		customData->read(reader);
		chunkCustomDataMap[customData->key] = customData;
	}

	reader.readBytes((unsigned char **)&pr[0], 256);
	reader.readBytes((unsigned char **)&jr[0], 256);
	reader.readBytes((unsigned char **)&fr[0], 256);

	cm.read(reader);
	vm.read(reader);
	gm.read(reader);
	km.read(reader);

	reader.readBoolean(&needsLightCalculation);

	int *entityCount;
	reader.readInt32(&entityCount);

	for (int k = 0; k < *entityCount; ++k) {
		EntityCreationData *entityCreationData;
		entityCreationData->read(reader);
		entityCreationDataList.push_back(entityCreationData);
	}

	int *tileEntityCount;
	reader.readInt32(&tileEntityCount);

	for (int l = 0; l < *tileEntityCount; ++l) {

	}

	unsigned short *entitySpawerCount;
	reader.readUInt16(&entitySpawerCount);

	for (int m = 0; m < *entitySpawerCount; ++m) {

	}

	bool *flag2;
	reader.readBoolean(&flag2);

	if (*flag2) {
		ur.resize(16);

		for (int n = 0; n < 16; ++n) {
			reader.readUInt16(&ur[n]);
		}
	}

	return false;
}

bool Chunk::unpackChunk(Chunk &chunk, std::vector<unsigned char>& zipped) {
	
	// Header of the PKZIP file will always have unzipped size stored on bytes 22 to 26.
	// We fetch it as to know how big the buffer has to be.
	int *unzippedSize = nullptr;

	BinaryMemoryReader reader(zipped);
	reader.seek(30, 0);
	reader.readInt32(&unzippedSize);
	
	std::vector<unsigned char> unzipped(*unzippedSize);

	bool unzipSuccess = unzipChunk(zipped, unzipped);

	if (unzipSuccess) {
		return readChunk(chunk, unzipped);
	}

	return false;
}

void Chunk::deletePointer(void *pointer) {
	if ((int)pointer <= memoryStart && (int)pointer >= memoryEnd) {
		delete pointer;
	}
}

void Chunk::deleteArray(void *pointer) {
	if ((int)pointer <= memoryStart && (int)pointer >= memoryEnd) {
		delete[] pointer;
	}
}

Chunk::Chunk() {}

Chunk::~Chunk() {}
