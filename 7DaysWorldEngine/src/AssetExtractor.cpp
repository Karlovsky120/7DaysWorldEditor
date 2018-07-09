#include "AssetExtractor.h"

#include "ObjectInfo.h"

#include "binaryIO/BinaryFileReader.h"

AssetExtractor::AssetExtractor() {}

AssetExtractor::~AssetExtractor() {}

void AssetExtractor::constructAssetTree() {

    for (auto it = assetMap.begin(); it != assetMap.end(); ++it) {

    }


}

void AssetExtractor::extractAssetInfo() {
    std::string address = "C:\\Programs\\Steam\\steamapps\\common\\7 Days To Die\\7DaysToDie_Data\\resources.assets";

    BinaryFileReader *reader = new BinaryFileReader(address);

    //20 bytes of header
    unsigned int metadataSize;
    reader->readBigEndian(metadataSize);

    unsigned int fileSize;
    reader->readBigEndian(fileSize);

    unsigned int fileFormat;
    reader->readBigEndian(fileFormat);

    unsigned int offsetToFirstFile;
    reader->readBigEndian(offsetToFirstFile);

    //littleEndian = 0, bigEndian = 1
    char endiannes;
    reader->read<char>(endiannes);

    //unknown 3 bytes, could be alignment
    reader->seek(3, seekEnum::cur);

    //TypeTree
    std::string unityVersion;
    reader->readCString(unityVersion);

    bool hasTypeTree;
    reader->read<bool>(hasTypeTree);

    //something is amiss here, not sure what but let's be lazy about it
    hasTypeTree = false;

    unsigned int version;
    reader->read<unsigned int>(version);

    unsigned int fieldCount;
    reader->read<unsigned int>(fieldCount);

    for (unsigned int i = 0; i < fieldCount; ++i) {
        int classId;
        reader->read<int>(classId);

        if (classId < 0) {
            //4 unsigned integer of unknown purpose
            reader->seek(16, seekEnum::cur);
        }

        //4 unsigned integer of unknown purpose
        reader->seek(16, seekEnum::cur);

        if (hasTypeTree) {
            unsigned int typeFieldsExCount;
            reader->read<unsigned int>(typeFieldsExCount);

            unsigned int stringTableLen;
            reader->read<unsigned int>(stringTableLen);

            reader->seek(typeFieldsExCount * 24 + stringTableLen, seekEnum::cur);
        }
    }

    unsigned int sizeFiles;
    reader->read<unsigned int>(sizeFiles);

    for (unsigned int i = 0; i < sizeFiles; ++i) {
        reader->alignTo4Bytes();

        AssetInfo *assetInfo = new AssetInfo();

        unsigned _int64 key;
        reader->read<unsigned _int64>(key);

        reader->read<unsigned int>(assetInfo->offset);
        reader->read<unsigned int>(assetInfo->size);
        reader->read<unsigned int>(assetInfo->type);
        // haven't read:
        // unsigned short inheritedUnityClass
        // unsigned short scriptIndex
        // unsigned char unknown

        assetMap.emplace(key, std::pair<AssetInfo*, Asset*>(assetInfo, nullptr));
    }
    /*
        int currentIndexOffset = reader->getPosition();

        //int absoluteOffset = offsetToFirstFile + asset.offset;

        //reader->seek(absoluteOffset, beg);

        //reader->readStringAlternate(asset.name);
        //align to 4 bytes
        reader.alignTo4Bytes();
        //}*/
}

