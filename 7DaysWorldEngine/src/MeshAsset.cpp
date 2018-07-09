#include "MeshAsset.h"

MeshAsset::~MeshAsset() {}

MeshAsset *MeshAsset::extractMesh(BinaryFileReader &reader) {
    //MeshAsset *meshAsset = new MeshAsset();

    reader.readString<unsigned int>(name);

    reader.alignTo4Bytes();



    //4 bytes
    //uint first byte
    //uint index count
    //(u?)int topology
    //uint first vertex
    //uint vertex count



    //local AABB
    //float center.x
    //float center.y
    //float center.z
    //float extend.x
    //float extend.y
    //float extend.z

    //8 bytes of data, should be mostly constant, perhaps few array I doubt 7dtd uses

    //uint index buffer length
    //indices as shorts for buffer length bytes

    //byte (skin array is zero?)
    //uint current channels
    //uint vertex count
    //uint channel count
    //4 bytes per channel 1 byte each parameter: stream, offset, format, dimension

    //uint length of data
    //data consists of vertices, normals and texture coordinates


    return nullptr;
}

MeshAsset::MeshAsset() {}
