#pragma once
#include "Asset.h"

#include "Transformation.h"

class Transform : public Asset {
public:
    unsigned int parentID;
    Transformation transformation;

    Transform();
    ~Transform();

    void readAsset(BinaryFileReader &reader);
};

