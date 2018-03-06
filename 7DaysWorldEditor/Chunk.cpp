#pragma once
#include "Chunk.h"

#include "BinaryMemoryReader.h"
#include "BinaryMemoryWriter.h"
#include "ChunkBlockLayer.h"
#include "ChunkCustomData.h"
#include "EntityCreationData.h"
#include "EntitySpawner.h"
#include "TileEntity.h"
#include "VersionCheck.h"

#include "Unzip.h"
#include "Zip.h"

// In the original code the flag is false and the streamMode is persistency.
int Chunk::read(BinaryMemoryReader &reader, bool &isValidRead) {
	isValidRead = true;

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
		std::shared_ptr<TileEntity> tileEntity = TileEntity::instantiate((TileEntityClassId)entityType);
		tileEntity->read(reader);
		tileEntityDictionary[tileEntity->localChunkPosition] = tileEntity;
	}

	unsigned short entitySpawnerCount;
	reader.read<unsigned short>(entitySpawnerCount);
	reader.read<unsigned char>(entitySpawnerListSaveVersion);

	reader.readMultipleComplex<EntitySpawner, unsigned short>(entitySpawnerList, entitySpawnerCount);

	reader.read<bool>(ur.first);

	if (ur.first) {
		for (int n = 0; n < 16; ++n) {
			reader.read<unsigned short>(ur.second[n]);
		}
	}

	reader.readMultipleSimple<int, unsigned char>(hk);

	isValidRead = reader.isValidRead();

	return 0;
}

void Chunk::write(BinaryMemoryWriter &writer) const {
	writer.write<int>(xm);
	writer.write<int>(mm);
	writer.write<int>(rm);

	writer.write<unsigned _int64>(savedInWorldTicks);

	for (int i = 0; i < 64; ++i) {
		bool chunkBlockLayerExists = cbl.find(i) != cbl.end();
		writer.write<bool>(chunkBlockLayerExists);

		if (chunkBlockLayerExists) {
			cbl.find(i)->second.write(writer);
		}
	}

	cbc.write(writer);

	writer.writeBytes(im, 256);
	writer.writeBytes(terrainHeight, 256);
	writer.writeBytes(biomeID, 256);
	writer.writeBytes(biomeIntentsity, 1536);

	writer.write<unsigned char>(dominantBiome);
	writer.write<unsigned char>(areaMasterDominantBiome);

#pragma warning (suppress: 4267)
	unsigned short customDataCount = chunkCustomDataMap.size();
	writer.write<unsigned short>(customDataCount);

	for (auto customData : chunkCustomDataMap) {
		customData.second.write(writer);
	}

	writer.writeBytes(pr, 256);
	writer.writeBytes(jr, 256);
	writer.writeBytes(fr, 256);

	cm.write(writer);
	vm.write(writer);
	gm.write(writer);
	km.write(writer);

	writer.write<bool>(needsLightCalculation);

	writer.writeMultipleComplex<EntityCreationData, int>(entityCreationDataList);

#pragma warning (suppress: 4267)
	int tileEntityCount = tileEntityDictionary.size();
	writer.write(tileEntityCount);

	for (auto tileEntity : tileEntityDictionary) {
		int tileEntityClassId = tileEntity.second->getType();

		writer.write<int>(tileEntityClassId);
		tileEntity.second->write(writer);
	}

#pragma warning (suppress: 4267)
	unsigned short entitySpawnerCount = entitySpawnerList.size();
	writer.write<unsigned short>(entitySpawnerCount);
	writer.write<unsigned char>(entitySpawnerListSaveVersion);

	writer.writeMultipleComplex<EntitySpawner, unsigned short>(entitySpawnerList, entitySpawnerCount);

	writer.write<bool>(ur.first);

	if (ur.first) {
		for (int n = 0; n < 16; ++n) {
			writer.write<unsigned short>(ur.second[n]);
		}
	}

	writer.writeMultipleSimple<int, unsigned char>(hk);
}

Chunk::Chunk() {}
Chunk::~Chunk() {}
