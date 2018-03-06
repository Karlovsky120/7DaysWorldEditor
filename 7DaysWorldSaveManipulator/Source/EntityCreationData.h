#pragma once
#include "BodyDamage.h"
#include "Coordinate.h"
#include "EntityStats.h"
#include "ItemStack.h"
#include "TileEntity.h"

#include <memory>

class BinaryMemoryReader;
class BinaryMemoryWriter;

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

	std::pair<bool, EntityStats> stats;

	short deathTime;

	int tileEntityType;
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

	int read(BinaryMemoryReader &reader);
	void write(BinaryMemoryWriter &writer) const;

	EntityCreationData();
	~EntityCreationData();
};
