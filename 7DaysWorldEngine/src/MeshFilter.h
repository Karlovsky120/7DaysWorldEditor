#pragma once
#include "Asset.h"

class MeshFilter : public Asset {
public:
    MeshFilter();
    ~MeshFilter();

    void readAsset(BinaryFileReader &reader) override;
};

