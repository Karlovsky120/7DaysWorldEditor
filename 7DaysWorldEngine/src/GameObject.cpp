#include "GameObject.h"

#include "binaryIO/BinaryFileReader.h"

GameObject::GameObject() {}

GameObject::~GameObject() {}

void GameObject::readAsset(BinaryFileReader &reader) {
    unsigned int childrenCount;
    reader.read<unsigned int>(childrenCount);

    for (unsigned int i = 0; i < childrenCount; ++i) {
        //unsigned int child asset type - no need to read it again   
        //unsigned int fileID - 0 is current file; It seems that I don't need it, so far
        reader.seek(8);

        unsigned int childID;
        reader.read<unsigned int>(childID);
        childrenVector.push_back(childID);

        //unsigned int name, seems to always be 0
        reader.seek(4);
    }

    //unsigned int layer
    reader.seek(4);

    reader.readString<unsigned int>(name);
    reader.alignTo4Bytes();

    //aligned to 4 bytes (unsigned?) short tag
    //bool isActive
}
