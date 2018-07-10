#pragma once

#include <string>
#include <vector>

class BinaryFileReader;

struct AssetType {
    enum AssetTypeEnum {
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
        Tree = 193,
        ParticleSystem = 198,
        ParticleSystemRenderer = 199,
        LODGroup = 205,
        BillboardAsset = 226,
        BillboardRenderer = 227
    };
};

class Asset {
public:
    unsigned _int64 index = 0;
    std::string name = "";
    unsigned int parentID = 0;
    std::vector<unsigned int> childrenVector;

    Asset();
    ~Asset();

    Asset static *generateAsset(AssetType::AssetTypeEnum type, unsigned _int64 index);
    void static initializeAssets();

    virtual void readAsset(BinaryFileReader &reader) = 0;
    void readAssetInfo(BinaryFileReader &reader, unsigned int &data);
};