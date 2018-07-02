#pragma once

#include "ChunkBlockChannel.h"
#include "Coordinate.h"
#include "EntitySpawner.h"
#include "ChunkBlockLayer.h"
#include "ChunkCustomData.h"
#include "EntityCreationData.h"

#include <array>
#include <map>
#include <memory>
#include <vector>

class BinaryMemoryReader;
class BinaryMemoryWriter;
class TileEntity;

class Chunk {
public:
    unsigned char header[4];
    unsigned int version;

    int xm;
    int mm;
    int rm;

    unsigned _int64 savedInWorldTicks;

    std::map<unsigned int, ChunkBlockLayer> cbl;

    ChunkBlockChannel<1> cbc;

    unsigned char im[256];
    unsigned char terrainHeight[256];
    unsigned char biomeID[256];
    unsigned char biomeIntentsity[1536];

    unsigned char dominantBiome;
    unsigned char areaMasterDominantBiome;

    std::map<std::string, ChunkCustomData> chunkCustomDataMap;

    unsigned char pr[256];
    unsigned char jr[256];
    unsigned char fr[256];

    ChunkBlockChannel<1> cm;
    ChunkBlockChannel<1> vm;
    ChunkBlockChannel<2> gm;
    ChunkBlockChannel<6> km;

    bool needsLightCalculation;

    std::vector<EntityCreationData> entityCreationDataList;	std::map<Coordinate<int>, std::shared_ptr<TileEntity>> tileEntityDictionary;

    unsigned char entitySpawnerListSaveVersion;
    std::vector<EntitySpawner> entitySpawnerList;
    std::pair<bool, std::array<unsigned short, 16>> ur;

    std::vector<int> hk;

    Chunk();
    ~Chunk();

    int read(BinaryMemoryReader &reader, bool &isValidRead);
    void write(BinaryMemoryWriter &writer) const;
};
