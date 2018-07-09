#pragma once

#include "Asset.h"

#include <vector>

class GameObject : public Asset {
public:
    GameObject();
    ~GameObject();

    void readAsset(BinaryFileReader &reader) override;
};

