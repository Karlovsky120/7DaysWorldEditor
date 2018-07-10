#pragma once
#include "Asset.h"

class MeshRenderer : public Asset {
public:
    MeshRenderer();
    ~MeshRenderer();

    void readAsset(BinaryFileReader &reader) override;
};

