#pragma once

#include "Coordinate.h"

#include <string>
#include <vector>

class BinaryMemoryReader;
class BinaryMemoryWriter;

class EntitySpawner {
public:
    unsigned char version;
    Coordinate<int> position;
    Coordinate<short> size;
    unsigned short triggerDiameter;
    std::string entitySpawnerClassName;

    short totalSpawnedThisWave;
    float timeDelayToNextWave;
    float timeDelayBetweenSpawns;

    unsigned char idVersion;

    std::vector<int> entitySpawnedIdList;

    short currentWave;
    int lastDaySpawnCalled;
    int numberToSpawnThisWave;

    unsigned _int64 worldTimeNextToWave;
    bool bCaveSpawn;

    EntitySpawner();
    ~EntitySpawner();

    int read(BinaryMemoryReader &reader);
    void write(BinaryMemoryWriter &writer) const;
};
