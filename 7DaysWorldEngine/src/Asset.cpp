#include "Asset.h"

#include "GameObject.h"

Asset::Asset() {}

Asset::~Asset() {}

Asset *Asset::generateAsset(AssetEnum::assetType type) {
    switch (type) {
    case AssetEnum::GameObject:
        return new GameObject();
    }
    return nullptr;
}
