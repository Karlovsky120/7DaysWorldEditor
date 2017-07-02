#include "EntityCreationData.h"

#include "BinaryMemoryReader.h"

void EntityCreationData::read(BinaryMemoryReader &reader) {
	reader.readByte(&entityCreationDataVersion);
	reader.readInt32(&entityClass);

	reader.readInt32(&id);
	reader.readSingle(&lifetime);

	reader.readSingle(&pos.x);
	reader.readSingle(&pos.y);
	reader.readSingle(&pos.z);

	reader.readSingle(&rot.x);
	reader.readSingle(&rot.y);
	reader.readSingle(&rot.z);

	reader.readBoolean(&onGround);

	bodyDamage.read(reader);

	// Given that this class is used for both players and all other
	// entities, only players should have stats. Hence, after this
	// goes a bit of code I'm to lazy to do, which should only matter
	// for the players.
	reader.readBoolean(&isStatsNotNull);

	reader.readInt16(&deathTime);

	
}

EntityCreationData::EntityCreationData() {}


EntityCreationData::~EntityCreationData() {}
