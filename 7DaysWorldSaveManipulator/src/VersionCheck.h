#pragma once

#include <string>

#define BODY_DAMAGE "bodyDamage"
#define BUFF "buff"
#define BUFF_DESCRIPTOR "buffDescriptor"
#define BUFF_TIMER "buffTimer"
#define BUFF_TIMER_SCHEDULED "buffTimerScheduled"
#define CHUNK "chunk"
#define ENTITY_CREATION_DATA "entityCreationData"
#define ENTITY_SPAWNER "entitySpawner"
#define ENTITY_STATS "entityStats"
#define ITEM_VALUE "itemValue"
#define MULTI_BUFF "multiBuff"
#define MULTI_BUFF_ACTION "multiBuffAction"
#define MULTI_BUFF_PREFAB_ATTACHMENT_DESCRIPTOR "multiBuffPrefabAttachmentDescriptor"
#define MULTI_BUFF_VARIABLE "multiBuffVariable"
#define BUFF_MODIFIER "buffModifier"
#define RECIPE "recipe"
#define STAT "stat"
#define STAT_MODIFIER "statModifier"
#define TILE_ENTITY "tileEntity"
#define TILE_ENTITY_SECURE "tileEntitySecure"
#define TILE_ENTITY_SECURE_LOOT_CONTAINER "tileEntitySecureLootContainer"
#define TILE_ENTITY_SIGN "tileEntitySign"
#define TILE_ENTITY_POWERED "tileEntityPowered"
#define TILE_ENTITY_TRADER "tileEntityTrader"
#define TILE_ENTITY_VENDING_MACHINE "tileEntityVendingMachine"
#define TILE_ENTITY_WORKSTATION "tileEntityWorkstation"
#define TRADER_DATA "traderData"

#define BODY_DAMAGE_VER 2
#define BUFF_VER 7
#define BUFF_DESCRIPTOR_VER 2
#define BUFF_TIMER_VER 1
#define BUFF_TIMER_SCHEDULED_VER 3
#define CHUNK_VER 38
#define ENTITY_CREATION_DATA_VER 25
#define ENTITY_SPAWNER_VER 3
#define ENTITY_STATS_VER 6
#define ITEM_VALUE_VER 3
#define MULTI_BUFF_VER 2
#define MULTI_BUFF_ACTION_VER 3
#define MULTI_BUFF_PREFAB_ATTACHMENT_DESCRIPTOR_VER 1
#define MULTI_BUFF_VARIABLE_VER 1
#define BUFF_MODIFIER_VER 1
#define RECIPE_VER 2
#define STAT_VER 5
#define STAT_MODIFIER_VER 4
#define TILE_ENTITY_VER 3
#define TILE_ENTITY_SECURE_VER 1
#define TILE_ENTITY_SECURE_LOOT_CONTAINER_VER 1
#define TILE_ENTITY_SIGN_VER 1
#define TILE_ENTITY_POWERED_VER 1
#define TILE_ENTITY_TRADER_VER 1
#define TILE_ENTITY_VENDING_MACHINE_VER 1
#define TILE_ENTITY_WORKSTATION_VER 30
#define TRADER_DATA_VER 1

class VersionCheck {
public:
    VersionCheck();
    ~VersionCheck();

    static void checkVersion(int readVersion, int expectedVersion, std::string objectName);
};
