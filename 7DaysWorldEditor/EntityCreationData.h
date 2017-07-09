#pragma once

#include "Coordinate.h"

class BinaryMemoryReader;
class BodyDamage;
class ItemStack;
class TileEntity;

enum SpawnerSource { Unindentified, Biome, StaticSpawner, Dynamic };

class EntityCreationData {
public:
	unsigned char *entityCreationDataVersion;
	int *entityClass;

	int *id;
	float *lifetime;

	Coordinate<float> pos;
	Coordinate<float> rot;

	bool *onGround;

	BodyDamage *bodyDamage;

	bool *isStatsNotNull;
	short *deathTime;

	TileEntity *lootContainer;
	Coordinate<int> homePosition;

	short *unknownD;
	SpawnerSource spawnerSource;

	int *belongsPlayerId;
	ItemStack *itemStack;

	unsigned int *blockValueRawData;

	Coordinate<int> blockPosition;
	Coordinate<float> fallTreeDir;

	unsigned char *entityData;
	bool *isTraderEntity;


	EntityCreationData *read(BinaryMemoryReader *const reader);

	EntityCreationData();
	~EntityCreationData();
};

