#include "EntityCreationData.h"

#include "BinaryMemoryReader.h"
#include "BodyDamage.h"
#include "ItemStack.h"
#include "TileEntity.h"
#include "Utils.h"

EntityCreationData *EntityCreationData::read(BinaryMemoryReader *const reader) {

	reader->read<unsigned char>(&entityCreationDataVersion);
	reader->read<int>(&entityClass);

	reader->read<int>(&id);
	reader->read<float>(&lifetime);

	reader->read<float>(&pos.x);
	reader->read<float>(&pos.y);
	reader->read<float>(&pos.z);

	reader->read<float>(&rot.x);
	reader->read<float>(&rot.y);
	reader->read<float>(&rot.z);

	reader->read<bool>(&onGround);

	bodyDamage->read(reader);

	// Given that this class is used for both players and all other
	// entities, only players should have stats. Hence, after this line
	// goes a bit of code I'm to lazy to write, which should only matter
	// for the players anyway.
	reader->read<bool>(&isStatsNotNull);

	//TODO

	reader->read<short>(&deathTime);

	bool *tileEntityNotNull;
	reader->read<bool>(&tileEntityNotNull);

	if (*tileEntityNotNull) {
		int *type;
		reader->read<int>(&type);
		lootContainer = TileEntity::instantiate((TileEntityType)*type);
		lootContainer->read(reader);
	}

	reader->read<int>(&homePosition.x);
	reader->read<int>(&homePosition.y);
	reader->read<int>(&homePosition.z);

	reader->read<short>(&unknownD);
	unsigned char *sourceType;
	reader->read<unsigned char>(&sourceType);
	spawnerSource = (SpawnerSource)*sourceType;

	if (*entityClass == Utils::getMonoHash("item")) {
		reader->read<int>(&belongsPlayerId);
		itemStack = new ItemStack();
		itemStack->read(reader);
	} else if (*entityClass == Utils::getMonoHash("fallingBlock")) {
		reader->read<unsigned int>(&blockValueRawData);
	} else if (*entityClass == Utils::getMonoHash("fallingTree")) {
		reader->read<int>(&blockPosition.x);
		reader->read<int>(&blockPosition.y);
		reader->read<int>(&blockPosition.z);

		reader->read<float>(&fallTreeDir.x);
		reader->read<float>(&fallTreeDir.y);
		reader->read<float>(&fallTreeDir.z);
	} else {
		// This code should not be reached, this reads the
		// player profile which should not be present here.
	}

	unsigned short *entityDataLength;
	reader->read<unsigned short>(&entityDataLength);

	if (*entityDataLength > 0) {
		reader->readBytes(&entityData, *entityDataLength);
	}

	reader->read<bool>(&isTraderEntity);

	return this;
}

EntityCreationData::EntityCreationData() {}
EntityCreationData::~EntityCreationData() {}
