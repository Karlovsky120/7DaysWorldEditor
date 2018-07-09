#include "Texture2D.h"

#include "binaryIO/BinaryFileReader.h"

Texture2D::Texture2D() {}

Texture2D::~Texture2D() {}

void Texture2D::readAsset(BinaryFileReader &reader) {
    reader.readStringAlternate(name);

    reader.read<unsigned int>(width);
    reader.read<unsigned int>(height);
    
    //unsigned int imageSize
    //unsigned int textureFormat
    //unsigned int mipCount
    //bool isReadable
    //bool isReadAllowed
    //align to 4 bytes
    //unsigned int imageCount
    reader.seek(20, seekEnum::cur);

    reader.read<unsigned int>(textureDimension);
    
    //unsigned int filterMode
    //unsigned int Aniso
    //unsigned int MipBias
    //unsigned int WrapMode

    //unsigned int lightMapFormat
    //unsigned int colourSpace
    reader.seek(24, seekEnum::cur);

    unsigned int dataLength;
    reader.read<unsigned int>(dataLength);

    //read image data
}
