#include "AssetExtractor.h"

#include "ObjectInfo.h"

#include "binaryIO/BinaryFileReader.h"

AssetExtractor::AssetExtractor() {}

AssetExtractor::~AssetExtractor() {}

void AssetExtractor::extract() {
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
    reader->seek(3, cur);

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
            reader->seek(16, cur);
        }

        //4 unsigned integer of unknown purpose
        reader->seek(16, cur);

        if (hasTypeTree) {
            unsigned int typeFieldsExCount;
            reader->read<unsigned int>(typeFieldsExCount);

            unsigned int stringTableLen;
            reader->read<unsigned int>(stringTableLen);

            reader->seek(typeFieldsExCount * 24 + stringTableLen, cur);
        }
    }

    unsigned int sizeFiles;
    reader->read<unsigned int>(sizeFiles);

    for (unsigned int i = 0; i < sizeFiles; ++i) {
        // align to 4 bytes
        reader->seek((4 - (reader->getPosition() % 4)) % 4, cur);

        ObjectInfo info;

        reader->read<unsigned _int64>(info.index);
        reader->read<unsigned int>(info.offset);
        reader->read<unsigned int>(info.size);
        reader->read<unsigned int>(info.type);
        reader->read<unsigned short>(info.inheritedUnityClass);
        reader->read<unsigned short>(info.scriptIndex);
        reader->read<unsigned char>(info.unknown);
    }
}

