#include "MeshRenderer.h"

#include "binaryIO/BinaryFileReader.h"

MeshRenderer::MeshRenderer() {}

MeshRenderer::~MeshRenderer() {}

void MeshRenderer::readAsset(BinaryFileReader &reader) {
    readAssetInfo(reader, parentID);

    //bool enabled
    //align to 4 bytes

    //bool cast shadows
    //bool recieve shadows
    //align to 4 bytes

    //unsigned short lightmap index
    //unsigned short lightmap index dynamic

    //vector4f (4*float) lightmap tiling offset
    //vector4f (4*float) lightmap tiling offset dynamic
    reader.seek(44);

    unsigned int materialCount;
    reader.read<unsigned int>(materialCount);

    for (unsigned int i = 0; i < materialCount; ++i) {
        unsigned int childID;
        readAssetInfo(reader, childID);
        childrenVector.push_back(childID);
    }

    //more data I currently don't care about
}
