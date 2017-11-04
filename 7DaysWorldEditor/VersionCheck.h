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
#define RECIPE_QUEUE_ITEM "recipeQueueItem"
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


#define NO_VERSION "noVersion"


#define CHECK_VERSION(value, objectName) {int versionCheck = checkVersion(value, objectName); if (versionCheck != 0) return versionCheck;}
#define CHECK_VERSION_R(value, objectName, reference) {int versionCheck = checkVersion(value, objectName); if (versionCheck != 0) reference = versionCheck;}
#define CHECK_VERSION_ZERO(value) {int versionCheck = value; if (versionCheck != 0) return versionCheck;}
#define CHECK_VERSION_ZERO_R(value, reference) {int versionCheck = value; if (versionCheck != 0) reference = versionCheck;}

class VersionCheck {
public:
	static int checkVersion(int readVersion, std::string objectName);

	VersionCheck();
	~VersionCheck();
};