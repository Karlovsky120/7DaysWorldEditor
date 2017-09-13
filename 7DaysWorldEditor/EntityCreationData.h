#pragma once
#include "BodyDamage.h"
#include "Coordinate.h"
#include "EntityStats.h"
#include "ItemStack.h"
#include "TileEntity.h"

#include <memory>

enum SpawnerSource {
	Unindentified,
	Biome,
	StaticSpawner,
	Dynamic
};

class EntityCreationData {
public:
	unsigned char entityCreationDataVersion;
	int entityClass;

	int id;
	float lifetime;

	Coordinate<float> pos;
	Coordinate<float> rot;

	bool onGround;

	BodyDamage bodyDamage;

	bool isStatsNotNull;

	EntityStats stats;

	short deathTime;

	std::shared_ptr<TileEntity> lootContainer;
	Coordinate<int> homePosition;

	short unknownD;
	unsigned char spawnerSource;

	int belongsPlayerId;
	ItemStack itemStack;
	char someSByte;

	unsigned int blockValue;

	Coordinate<int> blockPosition;
	Coordinate<float> fallTreeDir;

	std::vector<unsigned char> entityData;
	bool isTraderEntity;

	void read(BinaryMemoryReader &reader);

	EntityCreationData();
	~EntityCreationData();
};

