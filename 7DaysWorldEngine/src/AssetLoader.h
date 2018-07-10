#pragma once

#include "Asset.h"

#include <map>
#include <string>
#include <unordered_map>

struct AssetInfo {
    unsigned _int64 index;
    unsigned int offset;
    unsigned int size;
    unsigned int type;
};

struct AfterLoadEntry {
    unsigned int size;
    std::vector<unsigned char> *dest;
};

class AssetLoader {
public:
    static std::unordered_map<std::string, std::map<unsigned int, AfterLoadEntry>*>  afterLoadMap;
    unsigned int offsetToFirstFile;

	AssetLoader();
	~AssetLoader();

    void constructAssetTree(BinaryFileReader &reader);
	void extractAssetInfo(BinaryFileReader &reader);

private:
    std::unordered_map<unsigned _int64, std::pair<AssetInfo*, Asset*>> assetMap;
};

