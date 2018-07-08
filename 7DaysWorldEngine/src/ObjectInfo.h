#pragma once

#include <string>

// an incomplete list of asset types
enum assetType {
    Transform = 4,
    _2DTexture = 28,
    Mesh = 43,
    TextAsset = 49,
    BoxCollider = 65,
    AnimationClip = 74,
    AudioClip = 83,
    MonoScript = 115
};

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