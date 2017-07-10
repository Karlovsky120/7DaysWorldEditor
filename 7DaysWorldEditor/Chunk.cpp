#pragma once

#include "Chunk.h"

#include "BinaryMemoryReader.h"
#include "ChunkBlockLayer.h"
#include "ChunkCustomData.h"
#include "EntityCreationData.h"
#include "EntitySpawner.h"
#include "TileEntity.h"

#include "Unzip.h"
#include "Zip.h"

#include <log4cplus/logger.h>
#include <log4cplus/loggingmacros.h>

#include <fstream>

extern log4cplus::Logger mainLog;
extern std::string currentDirectory;

bool Chunk::unzipChunk(std::vector<unsigned char> &zipped, std::vector<unsigned char> &unzipped) {

	{ //DEBUG
		std::fstream bin(currentDirectory + "bin.zip", std::ios::out | std::ios::binary);
		bin.write((char *)&zipped[8], zipped.capacity() - 8);
		bin.close();
	}

	// Those 8 bytes are metadata we no longer need.
	#pragma warning(suppress: 4267) // Conversion from size_t to unsigned int - file will never be that large
	HZIP hz = OpenZip(&zipped[8], zipped.capacity() - 8, 0);

	ZIPENTRY ze;
	ZRESULT result = GetZipItem(hz, 0, &ze);

	if (result != ZR_OK) {
		LOG4CPLUS_ERROR(mainLog, LOG4CPLUS_TEXT("Failed to open zip file within the region file."));

		CloseZip(hz);
		return false;
	}

	#pragma warning(suppress: 4267) // Conversion from size_t to unsigned int - file will never be that large
	result = UnzipItem(hz, 0, &unzipped[0], unzipped.size());
	CloseZip(hz);

	if (result == ZR_OK) {
		unzipped.resize(ze.unc_size);

		{ //DEBUG
			std::fstream bout(currentDirectory + "bin.hex", std::ios::out | std::ios::binary);
			bout.write((char *)&unzipped[0], unzipped.capacity());
			bout.close();
		}
	}

	else {
		LOG4CPLUS_ERROR(mainLog, LOG4CPLUS_TEXT("Failed to unzip zip file within the region file."));
	}

	return result == ZR_OK;
}

bool Chunk::readChunk(Chunk &chunk, std::vector<unsigned char> &unzipped) {
	readMemoryStart = &unzipped[0];
	readMemoryEnd = &unzipped[unzipped.size()-1];

	BinaryMemoryReader reader(unzipped);

	reader.read<int>(&xm);
	reader.read<int>(&mm);
	reader.read<int>(&rm);

	reader.read<unsigned _int64>(&savedInWorldTicks);

	for (int i = 0; i < 64; ++i) {
		bool *flag;
		reader.read<bool>(&flag);

		if (*flag) {
			ChunkBlockLayer *cbLayer = new ChunkBlockLayer();
			cbl.push_back(cbLayer->read(&reader));
		}
	}

	cbc.read(&reader);

	reader.readBytes((unsigned char**)&im[0], 256);
	reader.readBytes((unsigned char**)&terrainHeight[0], 256);
	reader.readBytes((unsigned char**)&biomeID[0], 256);
	reader.readBytes((unsigned char**)&biomeIntentsity[0], 1536);

	reader.read<unsigned char>(&dominantBiome);
	reader.read<unsigned char>(&areaMasterDominantBiome);

	unsigned short *customDataCount;
	reader.read<unsigned short>(&customDataCount);

	for (int j = 0; j < *customDataCount; ++j) {
		ChunkCustomData *customData = new ChunkCustomData();
		customData->read(&reader);
		chunkCustomDataMap[customData->key] = customData;
	}

	reader.readBytes((unsigned char **)&pr[0], 256);
	reader.readBytes((unsigned char **)&jr[0], 256);
	reader.readBytes((unsigned char **)&fr[0], 256);

	cm.read(&reader);
	vm.read(&reader);
	gm.read(&reader);
	km.read(&reader);

	reader.read<bool>(&needsLightCalculation);

	reader.readMultipleComplex<EntityCreationData, int>(entityCreationDataList);

	int *tileEntityCount;
	reader.read<int>(&tileEntityCount);

	for (int k = 0; k < *tileEntityCount; ++k) {
		int* entityType;
		reader.read<int>(&entityType);
		TileEntity *tileEntity = TileEntity::instantiate((TileEntityType)*entityType);
		tileEntity->read(&reader);

		tileEntityDictionary[&tileEntity->localChunkPosition] = tileEntity;
	}

	unsigned short *entitySpawerCount;
	reader.read<unsigned short>(&entitySpawerCount);
	reader.read<unsigned char>(&entitySpawnerSaveVersion);

	reader.readMultipleComplex<EntitySpawner, unsigned short>(entitySpawnerList, entitySpawerCount);

	bool *flag2;
	reader.read<bool>(&flag2);

	if (*flag2) {
		for (int n = 0; n < 16; ++n) {
			unsigned short *urShort;
			reader.read<unsigned short>(&urShort);
			ur.push_back(urShort);
		}
	}

	bool t = reader.stream.capacity() == reader.position;

	return true;
}

bool Chunk::unpackChunk(Chunk &chunk, std::vector<unsigned char>& zipped) {
	
	// Header of the PKZIP file will always have unzipped size stored on bytes 22 to 26.
	// 22 + 8 bytes of metadata before the start of the PKZIP is 30.
	// We fetch it as to know how big the buffer has to be.
	int *unzippedSize = nullptr;

	BinaryMemoryReader reader(zipped);
	reader.seek(30, 0);
	reader.read<int>(&unzippedSize);
	
	std::vector<unsigned char> unzipped(*unzippedSize);

	bool unzipSuccess = unzipChunk(zipped, unzipped);

	if (unzipSuccess) {
		return readChunk(chunk, unzipped);
	}

	return false;
}

Chunk::Chunk() {}

Chunk::~Chunk() {}
