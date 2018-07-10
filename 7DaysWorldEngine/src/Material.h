#pragma once
#include "Asset.h"

#include "glm/glm.hpp"

#include <unordered_map>

struct TextureTypes {
    enum TextureTypeEnum {
        MainTex,
        BumpMap,
        BumpSpecMap,
        DetailTex,
        ShadowTex,
        TranslucencyMap,
        DetailAlbedoMap,
        DetailMask,
        DetailNormalMap,
        EmissionMap,
        OcclusionMap,
        ParallaxMap,
        SpecGlossMap
    };
};

struct TextureInfo {
    unsigned int textureID;
    glm::fvec2 scale;
    glm::fvec2 offset;
};

class Material : public Asset {
public:
    static std::unordered_map<std::string, TextureTypes::TextureTypeEnum> stringEnumMap;

    std::vector<std::pair<TextureTypes::TextureTypeEnum, TextureInfo>> textureVector;

    Material();
    ~Material();

    static void initializeTextureStringEnumMapping();

    void readAsset(BinaryFileReader &reader) override;
};

