#include "MeshAsset.h"

#include "binaryIO/BinaryFileReader.h"

MeshAsset::MeshAsset() {}

MeshAsset::~MeshAsset() {}

void MeshAsset::readAsset(BinaryFileReader &reader) {
    reader.readString<unsigned int>(name, true);

    unsigned int subMeshCount;
    reader.read<unsigned int>(subMeshCount);

    for (unsigned int i = 0; i < subMeshCount; ++i) {
        SubMesh *subMesh = new SubMesh();

        reader.read<unsigned int>(subMesh->subMeshMetadata.firstByte);
        reader.read<unsigned int>(subMesh->subMeshMetadata.indexCount);
        //unsigned int topology
        reader.seek(4);
        reader.read<unsigned int>(subMesh->subMeshMetadata.firstVertex);
        reader.read<unsigned int>(subMesh->subMeshMetadata.vertexCount);

        subMeshes.push_back(subMesh);

        //local AABB, unsigned int vec3 for positon and extend = 6*unsigned int
        reader.seek(24);
    }

    //shapes
    //vertices array
    reader.seekOverArray<unsigned int>(sizeof(unsigned int));
    //shapes array
    reader.seekOverArray<unsigned int>(sizeof(unsigned int));
    //channels array
    reader.seekOverArray<unsigned int>(sizeof(unsigned int));

    //unsigned int fullWeights
    reader.seek(4);

    //array bind poses
    reader.seekOverArray<unsigned int>(16 * sizeof(unsigned int), true);

    //array boneNameHashes
    reader.seekOverArray<unsigned int>(sizeof(unsigned int));

    //unsigned int rootBoneNameHash

    //char meshCompression 
    //bool isReadable
    //bool keepVertices
    //bool keepIndices
    reader.seek(8);

    unsigned int indicesDataLength;
    reader.read<unsigned int>(indicesDataLength);

    if (indicesDataLength != 0) {
        for (unsigned int i = 0; i < subMeshCount; ++i) {
            std::vector<unsigned char> temp;
            reader.readBytes(temp, subMeshes[i]->subMeshMetadata.indexCount * 2);
            subMeshes[i]->indices = std::vector<unsigned short>(temp.begin(), temp.end());
        }

        reader.seekToAlignTo4Bytes();
    }

    //array skin
    reader.seekOverArray<unsigned int>(8 * sizeof(unsigned int), true);

    //unsigned int currentChannels
    //unsigned int uncompressedVertexCount
    reader.seek(8);

    unsigned int channelCount;
    reader.read<unsigned int>(channelCount);

    reader.readBytes(channelStructureData, channelCount * 4);

    unsigned int vertexSize = 0;
    for (int i = 3; i < channelStructureData.size(); i += 4) {
        vertexSize += channelStructureData[i];
    }

    vertexSize *= 4;

    unsigned int vertexDataLength;
    reader.read<unsigned int>(vertexDataLength);

    if (vertexDataLength != 0) {
        for (auto it = subMeshes.begin(); it != subMeshes.end(); ++it) {
            reader.readBytes((*it)->perVertexData, vertexSize * (*it)->subMeshMetadata.vertexCount);
        }
    } else {
        //compressed mesh
        //this here is pain in the ass, and is only used by a single mesh I can do without, so, srew it, I'm not doing it
    }
}
