#include "Material.h"

#include "binaryIO/BinaryFileReader.h"

Material::Material() {}

Material::~Material() {}

void Material::initializeTextureStringEnumMapping() {
    stringEnumMap.emplace("_MainTex", TextureTypes::MainTex);
    stringEnumMap.emplace("_BumpMap", TextureTypes::BumpMap);
    stringEnumMap.emplace("_BumpSpecMap", TextureTypes::BumpSpecMap);
    stringEnumMap.emplace("_DetailsTex", TextureTypes::DetailTex);
    stringEnumMap.emplace("_ShadowTex", TextureTypes::ShadowTex);
    stringEnumMap.emplace("_TranslucencyMap", TextureTypes::TranslucencyMap);
    stringEnumMap.emplace("_DetailAlbedoMap", TextureTypes::DetailAlbedoMap);
    stringEnumMap.emplace("_DetailMask", TextureTypes::DetailMask);
    stringEnumMap.emplace("_DetailNormalMap", TextureTypes::DetailNormalMap);
    stringEnumMap.emplace("_EmissionMap", TextureTypes::EmissionMap);
    stringEnumMap.emplace("_OcclusionMap", TextureTypes::OcclusionMap);
    stringEnumMap.emplace("_ParallaxMap", TextureTypes::ParallaxMap);
    stringEnumMap.emplace("_SpecGlossMap", TextureTypes::SpecGlossMap);
}

void Material::readAsset(BinaryFileReader &reader) {
    reader.readString<unsigned int>(name);

    //unsigned int shader fileID
    //unsigned int shaderID
    //unsigned int unknown
    reader.seek(12);

    //don't want it, it's a cleaner way to skip over the bytes
    std::string shaderKeywords;
    reader.readString<unsigned int>(shaderKeywords);

    //unsigned int lightmap flags
    //int custom render queue
    //empty array stringTagMap

    unsigned int textureCount;
    reader.read<unsigned int>(textureCount);

    for (int i = 0; i < textureCount; ++i) {
        std::string textureName;
        reader.readString<unsigned int>(textureName);

        //unsigned int fileID
        reader.seek(4);

        TextureInfo textureInfo;

        reader.read<unsigned int>(textureInfo.textureID);

        //unsigned int unknown
        reader.seek(4);

        if (textureInfo.textureID != 0) {
            childrenVector.push_back(textureInfo.textureID);

            reader.read<float>(textureInfo.scale.x);
            reader.read<float>(textureInfo.scale.y);

            reader.read<float>(textureInfo.offset.x);
            reader.read<float>(textureInfo.offset.y);

            TextureTypes::TextureTypeEnum type = stringEnumMap.find(textureName)->second;
            textureVector.push_back(std::pair<TextureTypes::TextureTypeEnum, TextureInfo>(type, textureInfo));
        } else {
            reader.seek(20);
        }

        //more info I currently don't care about, mostly shader parameters
    }
}
