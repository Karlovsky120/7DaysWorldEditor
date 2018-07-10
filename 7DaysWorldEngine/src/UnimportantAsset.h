#pragma once

#include "Asset.h"

class UnimportantAsset : public Asset {
public:
    UnimportantAsset();
    ~UnimportantAsset();

    void readAsset(BinaryFileReader &reader) override;
};

