#pragma once

#include "Asset.h"

#include "binaryIO/BinaryFileReader.h"

#include <string>

struct SubMeshMetadata {
    unsigned int firstByte;
    unsigned int indexCount;
    //unsigned int topology
    unsigned int firstVertex;
    unsigned int vertexCount;
};

struct SubMesh {
    std::vector<unsigned char> perVertexData;
    SubMeshMetadata subMeshMetadata;

    std::vector<unsigned short> indices;
};

class MeshAsset : public Asset {
public:
    std::vector<SubMesh*> subMeshes;

    //0 vertices
    //1 normals
    //2 usually empty
    //3 uv coords
    //4-6 usually empty
    //7 4-dimensional unknown data
    std::vector<unsigned char> channelStructureData;
    //std::vector<char[4]> channelStructureData;

    MeshAsset();
    ~MeshAsset();

    void readAsset(BinaryFileReader &reader) override;
};

