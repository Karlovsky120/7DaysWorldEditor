#include "EntityCreationData.h"

#include "BinaryMemoryReader.h"
#include "BinaryMemoryWriter.h"
#include "Utils.h"
#include "VersionCheck.h"

EntityCreationData::EntityCreationData() {}
EntityCreationData::~EntityCreationData() {}

int EntityCreationData::read(BinaryMemoryReader &reader) {
    reader.read<unsigned char>(entityCreationDataVersion);
    VersionCheck::checkVersion(entityCreationDataVersion, ENTITY_CREATION_DATA_VER, ENTITY_CREATION_DATA);

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

    reader.read<bool>(stats.first);

    if (stats.first) {
        stats.second.read(reader);
    }

    reader.read<short>(deathTime);

    bool tileEntityNotNull;
    reader.read<bool>(tileEntityNotNull);

    if (tileEntityNotNull) {
        reader.read<int>(tileEntityType);
        lootContainer = TileEntity::instantiate((TileEntityClassId)tileEntityType);
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
        // Asuming this is used to read the map file.
    }

    unsigned short entityDataLength;
    reader.read<unsigned short>(entityDataLength);

    if (entityDataLength > 0) {
        reader.readBytes(entityData, entityDataLength);
    }

    reader.read<bool>(isTraderEntity);

    return 0;
}

void EntityCreationData::write(BinaryMemoryWriter &writer) const {
    writer.write<unsigned char>(entityCreationDataVersion);
    writer.write<int>(entityClass);

    writer.write<int>(id);
    writer.write<float>(lifetime);

    writer.write<float>(pos.x);
    writer.write<float>(pos.y);
    writer.write<float>(pos.z);

    writer.write<float>(rot.x);
    writer.write<float>(rot.y);
    writer.write<float>(rot.z);

    writer.write<bool>(onGround);

    bodyDamage.write(writer);

    writer.write<bool>(stats.first);

    if (stats.first) {
        stats.second.write(writer);
    }

    writer.write<short>(deathTime);

    bool tileEntityNotNull = lootContainer != nullptr;
    writer.write<bool>(tileEntityNotNull);

    if (tileEntityNotNull) {
        writer.write<int>(tileEntityType);
        lootContainer->write(writer);
    }

    writer.write<int>(homePosition.x);
    writer.write<int>(homePosition.y);
    writer.write<int>(homePosition.z);

    writer.write<short>(unknownD);
    writer.write<unsigned char>(spawnerSource);

    if (entityClass == Utils::getMonoHash("item")) {
        writer.write<int>(belongsPlayerId);
        itemStack.write(writer);
        writer.write<char>(someSByte);
    } else if (entityClass == Utils::getMonoHash("fallingBlock")) {
        writer.write<unsigned int>(blockValue);
    } else if (entityClass == Utils::getMonoHash("fallingTree")) {
        writer.write<int>(blockPosition.x);
        writer.write<int>(blockPosition.y);
        writer.write<int>(blockPosition.z);

        writer.write<float>(fallTreeDir.x);
        writer.write<float>(fallTreeDir.y);
        writer.write<float>(fallTreeDir.z);
    } else if (entityClass == Utils::getMonoHash("playerMale")
               || entityClass == Utils::getMonoHash("playerFemale")) {
        // This code should not be reached, this reads the
        // player profile which should not be present here.
    }

#pragma warning (suppress: 4267)
    writer.writeConst<unsigned short>(entityData.size());

    if (entityData.size() > 0) {
#pragma warning (suppress: 4267)
        unsigned short entityDataLength = entityData.size();
        writer.writeBytes(entityData, entityDataLength);
    }

    writer.write<bool>(isTraderEntity);
}
