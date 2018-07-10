#include "GameObject.h"

#include "binaryIO/BinaryFileReader.h"

GameObject::GameObject() {}

GameObject::~GameObject() {}

void GameObject::readAsset(BinaryFileReader &reader) {
    unsigned int childrenCount;
    reader.read<unsigned int>(childrenCount);

    for (unsigned int i = 0; i < childrenCount; ++i) {
        //unsigned int child asset type - no need to read it again
        reader.seek(4);

        unsigned int childID;
        readAssetInfo(reader, childID);
        childrenVector.push_back(childID);
    }

    //unsigned int layer
    reader.seek(4);

    reader.readString<unsigned int>(name, true);

    //(unsigned?) short tag
    //bool isActive
}
