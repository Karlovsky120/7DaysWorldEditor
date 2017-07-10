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
	Coordinate<short> size;
	unsigned short *triggerDiameter;
	std::string *entitySpawnerClassName;

	short *totalSpawnedThisWave;
	float *timeDelayToNextWave;
	float *timeDelayBetweenSpawns;

	unsigned char *idVersion;

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

