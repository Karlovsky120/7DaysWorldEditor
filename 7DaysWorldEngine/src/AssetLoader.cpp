#include "AssetLoader.h"

#include "binaryIO/BinaryFileReader.h"

std::unordered_map<std::string, std::map<unsigned int, AfterLoadEntry>*> AssetLoader::afterLoadMap;

AssetLoader::AssetLoader() {}

AssetLoader::~AssetLoader() {}

void AssetLoader::loadRelevantAssets(BinaryFileReader &reader) {
    Asset::initializeAssets();

    int count = 0;
    for (auto it = assetMap.begin(); it != assetMap.end();) {
        std::pair<AssetInfo *, Asset*> *assetPackage = &it->second;
        AssetInfo *info = assetPackage->first;

        AssetType::AssetTypeEnum type = (AssetType::AssetTypeEnum)info->type;
        Asset *asset = Asset::generateAsset(type, info->index);

        if (asset != nullptr) {
            ++count; //used for breakpoints during debugging
            reader.seek(offsetToFirstFile + info->offset, SeekPoint::beg);
            asset->readAsset(reader);
            assetPackage->second = asset;
            ++it;
        } else {
            //assets I have no need of
            it = assetMap.erase(it);
        }

        int p = 0;
    }
}

void AssetLoader::extractAssetInfo(BinaryFileReader &reader) {
    //20 bytes of header
    unsigned int metadataSize;
    reader.readBigEndian(metadataSize);

    unsigned int fileSize;
    reader.readBigEndian(fileSize);

    unsigned int fileFormat;
    reader.readBigEndian(fileFormat);

    reader.readBigEndian(offsetToFirstFile);

    //littleEndian = 0, bigEndian = 1
    char endiannes;
    reader.read<char>(endiannes);

    //unknown 3 bytes, could be alignment
    reader.seek(3);

    //TypeTree
    std::string unityVersion;
    reader.readCString(unityVersion);

    bool hasTypeTree;
    reader.read<bool>(hasTypeTree);

    //something is amiss here, not sure what but let's be lazy about it
    hasTypeTree = false;

    unsigned int version;
    reader.read<unsigned int>(version);

    unsigned int fieldCount;
    reader.read<unsigned int>(fieldCount);

    for (unsigned int i = 0; i < fieldCount; ++i) {
        int classId;
        reader.read<int>(classId);

        if (classId < 0) {
            //4 unsigned integer of unknown purpose
            reader.seek(16);
        }

        //4 unsigned integer of unknown purpose
        reader.seek(16);

        if (hasTypeTree) {
            unsigned int typeFieldsExCount;
            reader.read<unsigned int>(typeFieldsExCount);

            unsigned int stringTableLen;
            reader.read<unsigned int>(stringTableLen);

            reader.seek(typeFieldsExCount * 24 + stringTableLen);
        }
    }

    unsigned int sizeFiles;
    reader.read<unsigned int>(sizeFiles);

    reader.seekToAlignTo4Bytes();

    for (unsigned int i = 0; i < sizeFiles; ++i) {
        AssetInfo *assetInfo = new AssetInfo();

        reader.read<unsigned _int64>(assetInfo->index);
        reader.read<unsigned int>(assetInfo->offset);
        reader.read<unsigned int>(assetInfo->size);
        reader.read<int>(assetInfo->type);
        //unsigned short inheritedUnityClass
        //unsigned short scriptIndex
        //unsigned char unknown
        //align to 4 bytes
        reader.seek(8);

        assetMap.emplace(assetInfo->index, std::pair<AssetInfo*, Asset*>(assetInfo, nullptr));
    }
}

