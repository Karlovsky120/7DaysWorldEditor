#include "GameObject.h"

#include "binaryIO/BinaryFileReader.h"

GameObject::GameObject() {}

GameObject::~GameObject() {}

void GameObject::readAsset(BinaryFileReader &reader) {
    unsigned int childrenCount;
    reader.read<unsigned int>(childrenCount);

    for (int i = 0; i < childrenCount; ++i) {
        //unsigned int child asset type - no need to read it again   
        //unsigned int fileID - 0 is current file; It seems that I don't need it, so far
        reader.seek(8, seekEnum::cur);

        unsigned int childIndex;
        reader.read<unsigned int>(childIndex);
        childrenVector.push_back(childIndex);

        //unsigned int name, seems to always be 0
        reader.seek(4, seekEnum::cur);
    }

    //unsigned int layer
    reader.seek(4, seekEnum::cur);

    reader.readString<unsigned int>(name);
    reader.alignTo4Bytes();

    //aligned to 4 bytes (unsigned?) short tag
    //bool isActive
}
