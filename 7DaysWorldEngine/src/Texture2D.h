#pragma once

#include "Asset.h"

class Texture2D : public Asset {
public:
    unsigned int width, height, textureDimension;

    std::vector<char> imageData;

    Texture2D();
    ~Texture2D();

    void readAsset(BinaryFileReader &reader);
};

