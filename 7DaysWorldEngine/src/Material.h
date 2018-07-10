#pragma once
#include "Asset.h"

#include "glm/glm.hpp"

#include <string>
#include <unordered_map>
#include <utility>

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
        SpecGlossMap,
        MetallicGlossMap,
        Diffuse,
        ParticleTexture,
        Albedo,
        Normal,
        Occlusion,
        Refraction,
        Specular,
        LengthMap,
        Noise,
        MaskTex,
        Cubemap,
        DiffuseAlpha,
        Effects,
        Distortion,
        Sign,
        GlossMap,
        Animation,
        Cube,
        DisplacementMap,
        Illum,
        DiffuseRGBGlossA,
        Emission,
        DiffuseSpec,
        FlickerB,
        FlickerRG,
        Gloss,
        TorchLit,
        Color,
        Emissive,
        EmissiveAnimated,
        ColorMap,
        Frame,
        SpecMap,
        DistortionMap,
        Background,
        Mask,
        OuterSpaceCube,
        NormalMap,
        DiffuseGloss,
        SpecularTexture,
        Detail,
        Reflect,
        UVOff,
        Alpha,
        Clouds,
        Smoke,
        Texture,
        HeightMap,
        MaskMap
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

    static void initializeTextureStringEnumMap();

    void readAsset(BinaryFileReader &reader) override;
};

