#pragma once

#include "ChunkBlockChannel.h"
#include "Coordinate.h"

#include <map>
#include <vector>

class ChunkBlockLayer;
class ChunkCustomData;
class EntityCreationData;
class EntitySpawner;
class TileEntity;

class string;

class Chunk
{
private:
	unsigned char *readMemoryStart;
	unsigned char *readMemoryEnd;

	bool unzipChunk(std::vector<unsigned char> &zipped, std::vector<unsigned char> &unzipped);
	bool readChunk(Chunk &chunk, std::vector<unsigned char> &unzipped);

public:
	int *xm;
	int *mm;
	int *rm;

	unsigned _int64 *savedInWorldTicks;

	std::vector<ChunkBlockLayer *> cbl;

	ChunkBlockChannel cbc;

	unsigned char im[256];
	unsigned char terrainHeight[256];
	unsigned char biomeID[256];
	unsigned char biomeIntentsity[1536];

	unsigned char *dominantBiome;
	unsigned char *areaMasterDominantBiome;

	std::map<std::string *, ChunkCustomData *> chunkCustomDataMap;

	unsigned char pr[256];
	unsigned char jr[256];
	unsigned char fr[256];

	ChunkBlockChannel cm;
	ChunkBlockChannel vm;
	ChunkBlockChannel gm;
	ChunkBlockChannel km;

	bool *needsLightCalculation;

	std::vector<EntityCreationData *> entityCreationDataList;

	std::map<Coordinate<int> *, TileEntity *> tileEntityDictionary;

	unsigned char *entitySpawnerSaveVersion;

	std::vector<EntitySpawner *> entitySpawnerList;

	std::vector<unsigned short *> ur;

	bool unpackChunk(Chunk &chunk, std::vector<unsigned char> &zipped);

	Chunk();
	~Chunk();
};

