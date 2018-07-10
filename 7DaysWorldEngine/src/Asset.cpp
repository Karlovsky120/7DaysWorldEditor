#include "Asset.h"

#include "GameObject.h"
#include "Material.h"
#include "MeshAsset.h"
#include "MeshFilter.h"
#include "MeshRenderer.h"
#include "Texture2D.h"
#include "Transform.h"

Asset::Asset() {}

Asset::~Asset() {}

Asset *Asset::generateAsset(AssetType::AssetTypeEnum type, unsigned _int64 index) {
    Asset *asset = nullptr;

    switch (type) {
    case AssetType::GameObject:
        asset = new GameObject();
        break;
    case AssetType::Transform:
        asset = new Transform();
        break;
    case AssetType::Material:
        asset = new Material();
        break;
    case AssetType::MeshRenderer:
        //asset = new MeshRenderer();
        break;
    case AssetType::Texture2D:
        //asset = new Texture2D();
        break;
    case AssetType::MeshFilter:
        //asset = new MeshFilter();
        break;
    case AssetType::Mesh:
        //asset = new MeshAsset();
        break;
    default:
        break;
    }

    if (asset != nullptr) {
        asset->index = index;
    }

    return asset;
}

void Asset::initializeAssets() {
    Material::initializeTextureStringEnumMap();
}

void Asset::readAssetInfo(BinaryFileReader &reader, unsigned int &data) {
    //unsigned int fileID
    reader.seek(4);
    reader.read<unsigned int>(data);
    //unsigned int unknown
    reader.seek(4);
}
