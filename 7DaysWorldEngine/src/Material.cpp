#include "Material.h"

#include "binaryIO/BinaryFileReader.h"

std::unordered_map<std::string, TextureTypes::TextureTypeEnum>  Material::stringEnumMap;

Material::Material() {}

Material::~Material() {}

void Material::initializeTextureStringEnumMap() {
    stringEnumMap.emplace("_MainTex", TextureTypes::MainTex);
    stringEnumMap.emplace("_BumpMap", TextureTypes::BumpMap);
    stringEnumMap.emplace("_BumpSpecMap", TextureTypes::BumpSpecMap);
    stringEnumMap.emplace("_DetailTex", TextureTypes::DetailTex);
    stringEnumMap.emplace("_ShadowTex", TextureTypes::ShadowTex);
    stringEnumMap.emplace("_TranslucencyMap", TextureTypes::TranslucencyMap);
    stringEnumMap.emplace("_DetailAlbedoMap", TextureTypes::DetailAlbedoMap);
    stringEnumMap.emplace("_DetailMask", TextureTypes::DetailMask);
    stringEnumMap.emplace("_DetailNormalMap", TextureTypes::DetailNormalMap);
    stringEnumMap.emplace("_EmissionMap", TextureTypes::EmissionMap);
    stringEnumMap.emplace("_OcclusionMap", TextureTypes::OcclusionMap);
    stringEnumMap.emplace("_ParallaxMap", TextureTypes::ParallaxMap);
    stringEnumMap.emplace("_SpecGlossMap", TextureTypes::SpecGlossMap);
    stringEnumMap.emplace("_MetallicGlossMap", TextureTypes::MetallicGlossMap);
    stringEnumMap.emplace("_Diffuse", TextureTypes::Diffuse);
    stringEnumMap.emplace("_ParticleTexture", TextureTypes::ParticleTexture);
    stringEnumMap.emplace("_Albedo", TextureTypes::Albedo);
    stringEnumMap.emplace("_Normal", TextureTypes::Normal);
    stringEnumMap.emplace("_Occlusion", TextureTypes::Occlusion);
    stringEnumMap.emplace("_Refraction", TextureTypes::Refraction);
    stringEnumMap.emplace("_Specular", TextureTypes::Specular);
    stringEnumMap.emplace("_LengthMap", TextureTypes::LengthMap);
    stringEnumMap.emplace("_Noise", TextureTypes::Noise);
    stringEnumMap.emplace("_MaskTex", TextureTypes::MaskTex);
    stringEnumMap.emplace("_Cubemap", TextureTypes::Cubemap);
    stringEnumMap.emplace("_DiffuseAlpha", TextureTypes::DiffuseAlpha);
    stringEnumMap.emplace("_Effects", TextureTypes::Effects);
    stringEnumMap.emplace("_Distortion", TextureTypes::Distortion);
    stringEnumMap.emplace("_Sign", TextureTypes::Sign);
    stringEnumMap.emplace("_GlossMap", TextureTypes::GlossMap);
    stringEnumMap.emplace("_Animation", TextureTypes::Animation);
    stringEnumMap.emplace("_Cube", TextureTypes::Cube);
    stringEnumMap.emplace("_DisplacementMap", TextureTypes::DisplacementMap);
    stringEnumMap.emplace("_Illum", TextureTypes::Illum);
    stringEnumMap.emplace("_DiffuseRGBGlossA", TextureTypes::DiffuseRGBGlossA);
    stringEnumMap.emplace("_Emission", TextureTypes::Emission);
    stringEnumMap.emplace("_DiffuseSpec", TextureTypes::DiffuseSpec);
    stringEnumMap.emplace("_FlickerB", TextureTypes::FlickerB);
    stringEnumMap.emplace("_FlickerRG", TextureTypes::FlickerRG);
    stringEnumMap.emplace("_Gloss", TextureTypes::Gloss);
    stringEnumMap.emplace("_TorchLit", TextureTypes::TorchLit);
    stringEnumMap.emplace("_Color", TextureTypes::Color);
    stringEnumMap.emplace("_Emissive", TextureTypes::Emissive);
    stringEnumMap.emplace("_EmissiveAnimated", TextureTypes::EmissiveAnimated);
    stringEnumMap.emplace("_ColorMap", TextureTypes::ColorMap);
    stringEnumMap.emplace("_Frame", TextureTypes::Frame);
    stringEnumMap.emplace("_SpecMap", TextureTypes::SpecMap);
    stringEnumMap.emplace("_DistortionMap", TextureTypes::DistortionMap);
    stringEnumMap.emplace("_Background", TextureTypes::Background);
    stringEnumMap.emplace("_Mask", TextureTypes::Mask);
    stringEnumMap.emplace("_OuterSpaceCube", TextureTypes::OuterSpaceCube);
    stringEnumMap.emplace("_NormalMap", TextureTypes::NormalMap);
    stringEnumMap.emplace("_DiffuseGloss", TextureTypes::DiffuseGloss);
    stringEnumMap.emplace("_SpecularTexture", TextureTypes::SpecularTexture);
    stringEnumMap.emplace("_Detail", TextureTypes::Detail);
    stringEnumMap.emplace("_Reflect", TextureTypes::Reflect);
    stringEnumMap.emplace("_UVOff", TextureTypes::UVOff);
    stringEnumMap.emplace("_Alpha", TextureTypes::Alpha);
    stringEnumMap.emplace("_Clouds", TextureTypes::Clouds);
    stringEnumMap.emplace("_Smoke", TextureTypes::Smoke);
    stringEnumMap.emplace("_Texture", TextureTypes::Texture);
    stringEnumMap.emplace("_HeightMap", TextureTypes::HeightMap);
    stringEnumMap.emplace("_MaskMap", TextureTypes::MaskMap);
    //fuck you and fuck your bilion kinds of textures that are esentially the same thing
}

void Material::readAsset(BinaryFileReader &reader) {
    reader.readString<unsigned int>(name, true);

    //shader I don't care about
    unsigned int temp;
    readAssetInfo(reader, temp);

    reader.seekOverArray<unsigned int, unsigned char>(true);

    //unsigned int lightmap flags
    //int custom render queue
    reader.seek(8);

    //stringTagMap
    unsigned int arraySize;
    reader.read<unsigned int>(arraySize);

    for (unsigned int i = 0; i < arraySize * 2; ++i) {
        reader.seekOverArray<unsigned int, unsigned char>(true);
    }

    unsigned int textureCount;
    reader.read<unsigned int>(textureCount);

    for (unsigned int i = 0; i < textureCount; ++i) {
        std::string textureName;
        reader.readString<unsigned int>(textureName, true);

        TextureInfo textureInfo;
        readAssetInfo(reader, textureInfo.textureID);

        if (textureInfo.textureID != 0) {
            childrenVector.push_back(textureInfo.textureID);

            reader.read<float>(textureInfo.scale.x);
            reader.read<float>(textureInfo.scale.y);

            reader.read<float>(textureInfo.offset.x);
            reader.read<float>(textureInfo.offset.y);

            TextureTypes::TextureTypeEnum type = stringEnumMap.find(textureName)->second;
            textureVector.push_back(std::pair<TextureTypes::TextureTypeEnum, TextureInfo>(type, textureInfo));
        } else {
            reader.seek(16);
        }

        reader.seekToAlignTo4Bytes();
    }

    //more info I currently don't care about, mostly shader parameters
}
