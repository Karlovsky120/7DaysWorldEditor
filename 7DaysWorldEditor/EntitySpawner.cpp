#include "EntitySpawner.h"

#include "BinaryMemoryReader.h"
#include "BinaryMemoryWriter.h"

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

void EntitySpawner::write(BinaryMemoryWriter &writer) const {
	writer.write<unsigned char>(version);

	writer.write<int>(position.x);
	writer.write<int>(position.y);
	writer.write<int>(position.z);

	writer.write<short>(size.x);
	writer.write<short>(size.y);
	writer.write<short>(size.z);

	writer.write<unsigned short>(triggerDiameter);
	writer.write<std::string>(entitySpawnerClassName);

	writer.write<short>(totalSpawnedThisWave);
	writer.write<float>(timeDelayToNextWave);
	writer.write<float>(timeDelayBetweenSpawns);

#pragma warning (suppress: 4267)
	writer.writeConst<unsigned short>(entitySpawnedIdList.size());
	writer.write<unsigned char>(idVersion);

#pragma warning (suppress: 4267)
	unsigned short entitySpawnedIdListCount = entitySpawnedIdList.size();
	writer.writeMultipleSimple<int, unsigned short>(entitySpawnedIdList, entitySpawnedIdListCount);

	writer.write<short>(currentWave);
	writer.write<int>(lastDaySpawnCalled);
	writer.write<int>(numberToSpawnThisWave);

	writer.write<unsigned _int64>(worldTimeNextToWave);
	writer.write<bool>(bCaveSpawn);
}

EntitySpawner::EntitySpawner() {}
EntitySpawner::~EntitySpawner() {}