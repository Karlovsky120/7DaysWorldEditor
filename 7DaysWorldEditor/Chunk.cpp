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

extern log4cplus::Logger mainLog;
extern std::string currentDirectory;

// In the original code the flag is false and the streamMode is persistency.
void Chunk::readChunk(Chunk &chunk, BinaryMemoryReader &reader) {
 	reader.read<int>(xm);
	reader.read<int>(mm);
	reader.read<int>(rm);

	reader.read<unsigned _int64>(savedInWorldTicks);

	for (int i = 0; i < 64; ++i) {
		bool flag;
		reader.read<bool>(flag);

		if (flag) {	
			cbl[i] = ChunkBlockLayer();
			cbl[i].read(reader);
		}
	}

	cbc.read(reader);

	reader.readBytes(im, 256);
	reader.readBytes(terrainHeight, 256);
	reader.readBytes(biomeID, 256);
	reader.readBytes(biomeIntentsity, 1536);

	reader.read<unsigned char>(dominantBiome);
	reader.read<unsigned char>(areaMasterDominantBiome);

	unsigned short customDataCount;
	reader.read<unsigned short>(customDataCount);

	for (int j = 0; j < customDataCount; ++j) {
		ChunkCustomData customData;
		customData.read(reader);
		chunkCustomDataMap[customData.key] = customData;
	}

	reader.readBytes(pr, 256);
	reader.readBytes(jr, 256);
	reader.readBytes(fr, 256);

	cm.read(reader);
	vm.read(reader);
	gm.read(reader);
	km.read(reader);

	reader.read<bool>(needsLightCalculation);

	reader.readMultipleComplex<EntityCreationData, int>(entityCreationDataList);

	int tileEntityCount;
	reader.read<int>(tileEntityCount);

	for (int k = 0; k < tileEntityCount; ++k) {
		int entityType;
		reader.read<int>(entityType);
		std::shared_ptr<TileEntity> tileEntity = TileEntity::instantiate((TileEntityType)entityType);
		tileEntity->read(reader);
		tileEntityDictionary[tileEntity->localChunkPosition] = tileEntity;
	}

	unsigned short entitySpawnerCount;
	reader.read<unsigned short>(entitySpawnerCount);
	reader.read<unsigned char>(entitySpawnerListSaveVersion);

	reader.readMultipleComplex<EntitySpawner, unsigned short>(entitySpawnerList, entitySpawnerCount);

	bool flag2;
	reader.read<bool>(flag2);

	if (flag2) {
		for (int n = 0; n < 16; ++n) {
			unsigned short urShort;
			reader.read<unsigned short>(urShort);
			ur.push_back(urShort);
		}
	}

	//sleeperVolumeList = new std::vector<SleeperVolume *>();
	//reader.readMultipleComplex<SleeperVolume, unsigned char>(sleeperVolumeList);
	
	reader.readMultipleSimple<int, unsigned char>(hk);

	//reader.read<bool>(isEdited);

	if (reader.length != reader.position) {
		int a = 5;
	}

	//assert(reader.length == reader.position);
}

bool Chunk::unpackChunk(Chunk &chunk, std::vector<unsigned char>& zipped) {
	memcpy(&header[0], &zipped[0], 4);
	memcpy(&version, &zipped[4], 4);

	BinaryMemoryReader reader = BinaryMemoryReader(zipped);
	readChunk(chunk, reader);

	return true;
}

Chunk::Chunk() {}
Chunk::~Chunk() {}
