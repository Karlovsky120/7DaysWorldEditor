#include "Texture2D.h"

#include "AssetLoader.h"

#include "binaryIO/BinaryFileReader.h"

#include <utility>

Texture2D::Texture2D() {}

Texture2D::~Texture2D() {}

void Texture2D::readAsset(BinaryFileReader &reader) {
    reader.readString<unsigned int>(name, true);

    reader.read<unsigned int>(width);
    reader.read<unsigned int>(height);

    //unsigned int imageSize
    //unsigned int textureFormat
    //unsigned int mipCount
    //bool isReadable
    //bool isReadAllowed
    //align to 4 bytes
    //unsigned int imageCount
    reader.seek(20);

    reader.read<unsigned int>(textureDimension);

    //unsigned int filterMode
    //unsigned int Aniso
    //unsigned int MipBias
    //unsigned int WrapMode

    //unsigned int lightMapFormat
    //unsigned int colourSpace
    reader.seek(24);

    unsigned int dataLength;
    reader.read<unsigned int>(dataLength);

    if (dataLength != 0) {
        //Required data is in this file
        reader.readBytes(textureData, dataLength);
    } else {
        //Required data is in separate file, set up to be loaded together with others later
        AfterLoadEntry entry;

        unsigned int offset;
        reader.read<unsigned int>(offset);

        reader.read<unsigned int>(entry.size);
        entry.dest = &textureData;

        std::string srcName;
        reader.readString<unsigned int>(srcName, true);

        //See if there already is an asset to be loaded from that file
        auto it = AssetLoader::afterLoadMap.find(srcName);

        std::map<unsigned int, AfterLoadEntry> *fileEntries;
        if (it != AssetLoader::afterLoadMap.end()) {
            fileEntries = it->second;
        } else {
            //If there weren't any assets from this file yet, create a new map
            fileEntries = new std::map<unsigned int, AfterLoadEntry>;
            AssetLoader::afterLoadMap.emplace(srcName, fileEntries);
        }

        //Add this asset data to be loaded from file
        fileEntries->emplace(offset, entry);
    }
}
