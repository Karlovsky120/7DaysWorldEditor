#include "EntitySpawner.h"

#include "BinaryMemoryReader.h"

EntitySpawner *EntitySpawner::read(BinaryMemoryReader * const reader) {
	reader->read<unsigned char>(&version);
	reader->read<int>(&position.x);
	reader->read<int>(&position.y);
	reader->read<int>(&position.z);

	reader->read<unsigned short>(&size.x);
	reader->read<unsigned short>(&size.y);
	reader->read<unsigned short>(&size.z);

	reader->read<unsigned short>(&triggerDiameter);
	reader->read<std::string>(&entitySpawnerClassName);

	reader->read<unsigned short>(&totalSpawnedThisWave);
	reader->read<float>(&timeDelayToNextWave);
	reader->read<float>(&timeDelayBetweenSpawns);

	unsigned short *entitySpawnedIdCount;
	reader->read<unsigned short>(&entitySpawnedIdCount);
	reader->read<unsigned short>(&idVersion);

	reader->readMultipleSimple<int, unsigned short>(entitySpawnedIdList);
	
	reader->read<short>(&currentWave);
	reader->read<int>(&lastDaySpawnCalled);
	reader->read<int>(&numberToSpawnThisWave);

	reader->read<unsigned _int64>(&worldTimeNextToWave);
	reader->read<bool>(&bCaveSpawn);

	return this;
}

EntitySpawner::EntitySpawner() {}
EntitySpawner::~EntitySpawner() {}