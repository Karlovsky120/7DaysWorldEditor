#pragma once

#include "Asset.h"

#include <string>
#include <unordered_map>

struct AssetInfo {
    unsigned _int64 index;
    unsigned int offset;
    unsigned int size;
    unsigned int type;
};

class AssetExtractor {
public:
	AssetExtractor();
	~AssetExtractor();

    void constructAssetTree();
	void extractAssetInfo();

private:
    std::unordered_map<unsigned _int64, std::pair<AssetInfo*, Asset*>> assetMap;
};

