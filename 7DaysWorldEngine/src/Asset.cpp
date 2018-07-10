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

Asset *Asset::generateAsset(AssetType::AssetTypeEnum type) {
    switch (type) {
    case AssetType::GameObject:
        return new GameObject();
    case AssetType::Transform:
        return new Transform();
    case AssetType::Material:
        return new Material();
    case AssetType::MeshRenderer:
        return new MeshRenderer();
    case AssetType::Texture2D:
        return new Texture2D();
    case AssetType::MeshFilter:
        return new MeshFilter();
    case AssetType::Mesh:
        return new MeshAsset();
    default:
        return nullptr;
    }
}

void Asset::initializeAssets() {
    Material::initializeTextureStringEnumMap();
}
