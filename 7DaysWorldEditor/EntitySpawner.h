#pragma once

#include "Coordinate.h"

#include <string>
#include <vector>

class BinaryMemoryReader;

class EntitySpawner
{
public:
	unsigned char *version;
	Coordinate<int> position;
	Coordinate<unsigned short> size;
	unsigned short *triggerDiameter;
	std::string *entitySpawnerClassName;

	unsigned short *totalSpawnedThisWave;
	float *timeDelayToNextWave;
	float *timeDelayBetweenSpawns;

	unsigned short *idVersion;

	std::vector<int *> entitySpawnedIdList;

	short *currentWave;
	int *lastDaySpawnCalled;
	int *numberToSpawnThisWave;

	unsigned _int64 *worldTimeNextToWave;
	bool *bCaveSpawn;

	EntitySpawner *read(BinaryMemoryReader *const reader);

	EntitySpawner();
	~EntitySpawner();
};

