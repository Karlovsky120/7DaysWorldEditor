#include "EntityCreationData.h"

#include "BinaryMemoryReader.h"
#include "BodyDamage.h"
#include "EntityStats.h"
#include "ItemStack.h"
#include "TileEntity.h"
#include "Utils.h"

void EntityCreationData::read(BinaryMemoryReader &reader) {

	reader.read<unsigned char>(entityCreationDataVersion);
	reader.read<int>(entityClass);

	reader.read<int>(id);
	reader.read<float>(lifetime);

	reader.read<float>(pos.x);
	reader.read<float>(pos.y);
	reader.read<float>(pos.z);

	reader.read<float>(rot.x);
	reader.read<float>(rot.y);
	reader.read<float>(rot.z);

	reader.read<bool>(onGround);
	
	bodyDamage.read(reader);

	reader.read<bool>(isStatsNotNull);

	if (isStatsNotNull) {
		stats.read(reader);
	}

	reader.read<short>(deathTime);

	bool tileEntityNotNull;
	reader.read<bool>(tileEntityNotNull);

	if (tileEntityNotNull) {
		int type;
		reader.read<int>(type);
		lootContainer = TileEntity::instantiate((TileEntityType)type);
		lootContainer->read(reader);
	}

	reader.read<int>(homePosition.x);
	reader.read<int>(homePosition.y);
	reader.read<int>(homePosition.z);

	reader.read<short>(unknownD);
	reader.read<unsigned char>(spawnerSource);

	if (entityClass == Utils::getMonoHash("item")) {
		reader.read<int>(belongsPlayerId);
		itemStack.read(reader);
		reader.read<char>(someSByte);
	} else if (entityClass == Utils::getMonoHash("fallingBlock")) {
		reader.read<unsigned int>(blockValue);
	} else if (entityClass == Utils::getMonoHash("fallingTree")) {
		reader.read<int>(blockPosition.x);
		reader.read<int>(blockPosition.y);
		reader.read<int>(blockPosition.z);

		reader.read<float>(fallTreeDir.x);
		reader.read<float>(fallTreeDir.y);
		reader.read<float>(fallTreeDir.z);
	} else if (entityClass == Utils::getMonoHash("playerMale")
		|| entityClass == Utils::getMonoHash("playerFemale")) {
		// This code should not be reached, this reads the
		// player profile which should not be present here.
	}
	
	unsigned short entityDataLength;
	reader.read<unsigned short>(entityDataLength);

	if (entityDataLength > 0) {
		reader.readBytes(entityData, entityDataLength);
	}

	reader.read<bool>(isTraderEntity);
}

EntityCreationData::EntityCreationData() {}
EntityCreationData::~EntityCreationData() {}
