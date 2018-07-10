#pragma once
#include "Asset.h"

#include "Transformation.h"

class Transform : public Asset {
public:
    Transformation transformation;

    Transform();
    ~Transform();

    void readAsset(BinaryFileReader &reader) override;
};

