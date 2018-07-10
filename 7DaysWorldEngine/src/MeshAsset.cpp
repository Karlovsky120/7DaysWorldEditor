#include "MeshAsset.h"

#include "binaryIO/BinaryFileReader.h"

MeshAsset::MeshAsset() {}

MeshAsset::~MeshAsset() {}

void MeshAsset::readAsset(BinaryFileReader &reader) {
    reader.readString<unsigned int>(name, true);

    unsigned int subMeshCount;
    reader.read<unsigned int>(subMeshCount);

    SubMesh subMesh;

    for (unsigned int i = 0; i < subMeshCount; ++i) {
        reader.read<unsigned int>(subMesh.subMeshMetadata.firstByte);
        reader.read<unsigned int>(subMesh.subMeshMetadata.indexCount);
        //unsigned int topology
        reader.seek(4);
        reader.read<unsigned int>(subMesh.subMeshMetadata.firstVertex);
        reader.read<unsigned int>(subMesh.subMeshMetadata.vetexCount);

        //local AABB, unsigned int vec3 for positon and extend = 6*unsigned int
        reader.seek(24);
    }

    subMeshes.push_back(subMesh);

    //shapes
    //unsigned int vertices
    //unsigned int shapes
    //unsigend int channels
    //unsigned int fullWeights

    //unsigned int bindPose
    //unsigned int boneNameHashes
    //unsigned int rootBoneNameHash

    //char meshCompression 
    //bool isReadable
    //bool keepVertices
    //bool keepIndices

    //unsigned int indicesDataLength - can reconstruct from metadata
    reader.seek(36);

    for (unsigned int i = 0; i < subMeshCount; ++i) {
        std::vector<unsigned char> temp;
        reader.readBytes(temp, subMeshes[i].subMeshMetadata.indexCount * 2);
        subMeshes[i].indices = std::vector<unsigned short>(temp.begin(), temp.end());
    }

    //unsigned int skin
    //unsigned int currentChannels

    //unsigned int vertexCount
    reader.seek(12);

    unsigned int channelCount;
    reader.read<unsigned int>(channelCount);

    for (unsigned int i = 0; i < channelCount; ++i) {
        //unsigned char stream
        reader.seek(1);

        unsigned char offset;
        reader.read<unsigned char>(offset);

        //unsigned char format
        reader.seek(1);

        unsigned char dimension;
        reader.read<unsigned char>(dimension);

        if (dimension != 0) {
            channelStructureData.push_back(std::pair<unsigned char, unsigned char>(offset, dimension));
        }
    }

    //unsigned int vertexDataLength
    reader.seek(4);

    unsigned int vertexSize = 0;
    for (auto it = channelStructureData.begin(); it != channelStructureData.end(); ++it) {
        vertexSize += it->second;
    }

    vertexSize *= 4;

    for (auto it = subMeshes.begin(); it != subMeshes.end(); ++it) {
        reader.readBytes(it->perVertexData, vertexSize * it->subMeshMetadata.vetexCount);
    }

    //more info I don't care about at this point
}
