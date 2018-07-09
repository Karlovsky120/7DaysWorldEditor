#pragma once

#include "Asset.h"

#include "binaryIO/BinaryFileReader.h"

#include <string>

class MeshAsset : public Asset {
public:
    std::string name;

    ~MeshAsset();

    MeshAsset *extractMesh(BinaryFileReader &reader);
private:
    MeshAsset();
};

