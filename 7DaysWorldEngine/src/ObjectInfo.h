#pragma once

#include <string>

// an incomplete list of asset types

class AssetObject {
public:
    unsigned _int64 index;
    unsigned int offset;
    unsigned int size;
    unsigned int type;
    unsigned short inheritedUnityClass;
    unsigned short scriptIndex;
    unsigned char unknown;

    std::string name;

    AssetObject();
    ~AssetObject();
};