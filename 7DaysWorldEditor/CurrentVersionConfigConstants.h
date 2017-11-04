#pragma once

#define CHECK_VERSION(function, objectName) {int versionCheck = checkVersion(function, objectName); if (versionCheck != 0) return versionCheck;}
#define CHECK_VERSION_R(function, objectName, reference) {int versionCheck = checkVersion(function, objectName); if (versionCheck != 0) reference = versionCheck;}
#define CHECK_VERSION_ZERO(version) {int versionCheck = version; if (versionCheck != 0) return versionCheck;}
#define CHECK_VERSION_ZERO_R(version, reference) {int versionCheck = version; if (versionCheck != 0) reference = versionCheck;}


/*versionCheck = checkVersion(version, TILE_ENTITY_SIGN_VERSION);
if (versionCheck != 0) return versionCheck;*/

/*#define CHECK_VERSION(readFunction, valueToCheck) {\
    int readVersion = readFunction; \
    int expectedVersion; \
    saveVersion.getProperty(valueToCheck, expectedVersion);\
    if (readVersion != expectedVersion) { \
        std::string errorMsg = "Version mismatch! Expected " + std::to_string(expectedVersion) + ", but read " + std::to_string(readVersion) + " for " + valueToCheck; \
        LOG4CPLUS_ERROR(mainLog, LOG4CPLUS_TEXT(errorMsg)); \
        readVersion = expectedVersion > readVersion ? -readVersion : readVersion; \
        return readVersion; \
    } \
} \

/*versionMatch = cbc.read(reader);
int expectedVersion;
saveVersion.getProperty(CHUNK_BLOCK_CHANNEL_VER, expectedVersion);
if (versionMatch != expectedVersion) {
	std::string errorMsg = "Version mismatch! Expected " + std::to_string(expectedVersion) + ", read " + std::to_string(versionMatch) + " for " + CHUNK_BLOCK_CHANNEL_VER;
	LOG4CPLUS_ERROR(mainLog, LOG4CPLUS_TEXT(errorMsg));
	// Return a negative value of read version if the version is older than the expected version.
	versionMatch = expectedVersion > versionMatch ? -versionMatch : versionMatch;
	return versionMatch;
}*/


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
#define TILE_ENTITY_POWERED "tileEnityPowered"
#define TILE_ENTITY_VENDING_MACHINE "tileEntityVendingMachine"
#define TRADER_DATA "traderData"


#define NO_VERSION "zeroVersion"
