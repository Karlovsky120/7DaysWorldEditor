#include "MeshRenderer.h"

#include "binaryIO/BinaryFileReader.h"

MeshRenderer::MeshRenderer() {}

MeshRenderer::~MeshRenderer() {}

void MeshRenderer::readAsset(BinaryFileReader &reader) {
    //unsigned int parent fileID
    reader.seek(4);

    reader.read<unsigned int>(parentID);
    //unsigned int unknown

    //bool enabled
    //align to 4 bytes

    //bool cast shadows
    //bool recieve shadows
    //align to 4 bytes

    //unsigned short lightmap index
    //unsigned short lightmap index dynamic

    //4*float lightmap tiling offset
    //4*float lightmap tiling offset dynamic
    reader.seek(48);

    unsigned int materialCount;
    reader.read<unsigned int>(materialCount);

    for (int i = 0; i < materialCount; ++i) {
        //unsigned int fileID
        reader.seek(4);

        unsigned int childID;
        reader.read<unsigned int>(childID);
        childrenVector.push_back(childID);

        //unsigned int unknown
        reader.seek(4);
    }

    //more data I currently don't care about
}
