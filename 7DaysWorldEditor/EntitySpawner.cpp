#include "EntitySpawner.h"

#include "BinaryMemoryReader.h"

void EntitySpawner::read(BinaryMemoryReader &reader) {
	reader.read<unsigned char>(version);

	reader.read<int>(position.x);
	reader.read<int>(position.y);
	reader.read<int>(position.z);

	reader.read<short>(size.x);
	reader.read<short>(size.y);
	reader.read<short>(size.z);

	reader.read<unsigned short>(triggerDiameter);
	reader.read<std::string>(entitySpawnerClassName);

	reader.read<short>(totalSpawnedThisWave);
	reader.read<float>(timeDelayToNextWave);
	reader.read<float>(timeDelayBetweenSpawns);

	unsigned short entitySpawnedIdCount;
	reader.read<unsigned short>(entitySpawnedIdCount);
	reader.read<unsigned char>(idVersion);

	reader.readMultipleSimple<int, unsigned short>(entitySpawnedIdList, entitySpawnedIdCount);
	
	reader.read<short>(currentWave);
	reader.read<int>(lastDaySpawnCalled);
	reader.read<int>(numberToSpawnThisWave);

	reader.read<unsigned _int64>(worldTimeNextToWave);
	reader.read<bool>(bCaveSpawn);
}

EntitySpawner::EntitySpawner() {}
EntitySpawner::~EntitySpawner() {}