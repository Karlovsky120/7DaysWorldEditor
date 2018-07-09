#pragma once

#include <string>
#include <vector>

class BinaryFileReader;

struct AssetEnum {
    enum assetType {
        GameObject = 1,
        Transform = 4,
        Material = 21,
        MeshRenderer = 23,
        Texture2D = 28,
        MeshFilter = 33,
        Mesh = 43,
        TextAsset = 49,
        RigidBoy = 54,
        BoxCollider = 65,
        AnimationClip = 74,
        AudioClip = 83,
        Avatar = 90,
        AnimatorController = 91,
        CGProgram = 109,
        MonoBehaviour = 114,
        MonoScript = 115,
        Font = 128,
        CapsuleCollider = 136,
        SkinnedMeshRendered = 137,
        AssetBundle = 142,
        CharacterJoint = 144,
        LODGroup = 205
    };
};

class Asset {
public:
    std::string name;
    std::vector<unsigned int> childrenVector;

    Asset();
    ~Asset();

    Asset *generateAsset(AssetEnum::assetType type);

    virtual void readAsset(BinaryFileReader &reader) = 0;
};