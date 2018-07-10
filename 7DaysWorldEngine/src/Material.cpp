#include "Material.h"

#include "binaryIO/BinaryFileReader.h"

std::unordered_map<std::string, TextureTypes::TextureTypeEnum>  Material::stringEnumMap;

Material::Material() {}

Material::~Material() {}

void Material::initializeTextureStringEnumMap() {
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
    stringEnumMap.emplace("_MetallicGlossMap", TextureTypes::MetallicGlossMap);
    stringEnumMap.emplace("_Diffuse", TextureTypes::Diffuse);
}

void Material::readAsset(BinaryFileReader &reader) {
    reader.readString<unsigned int>(name, true);

    unsigned int temp;
    readAssetInfo(reader, temp);

    reader.seekOverArray<unsigned int, unsigned char>(true);

    //unsigned int lightmap flags
    //int custom render queue
    //empty array stringTagMap
    reader.seek(12);

    unsigned int textureCount;
    reader.read<unsigned int>(textureCount);

    for (unsigned int i = 0; i < textureCount; ++i) {
        std::string textureName;
        reader.readString<unsigned int>(textureName, true);

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

            if (stringEnumMap.find(textureName) == stringEnumMap.end()) {
                int breakp = 0;
            }

            TextureTypes::TextureTypeEnum type = stringEnumMap.find(textureName)->second;
            textureVector.push_back(std::pair<TextureTypes::TextureTypeEnum, TextureInfo>(type, textureInfo));
        } else {
            reader.seek(16);
        }

        reader.seekToAlignTo4Bytes();
    }

    //more info I currently don't care about, mostly shader parameters
}
