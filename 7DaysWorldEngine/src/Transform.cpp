#include "Transform.h"

#include "binaryIO/BinaryFileReader.h"

Transform::Transform() {}

Transform::~Transform() {}

void Transform::readAsset(BinaryFileReader &reader) {
    readAssetInfo(reader, parentID);

    float coords[4];

    //rotation
    for (int i = 0; i < 4; ++i) {
        reader.read<float>(coords[i]);
    }

    transformation.setRotation(glm::quat(coords[3], coords[0], coords[1], coords[2]));

    //position
    for (int i = 0; i < 3; ++i) {
        reader.read<float>(coords[i]);
    }

    transformation.setPosition(glm::vec3(coords[0], coords[1], coords[2]));

    //scale
    for (int i = 0; i < 3; ++i) {
        reader.read<float>(coords[i]);
    }

    transformation.setScale(glm::vec3(coords[0], coords[1], coords[2]));

    unsigned int childrenCount;
    reader.read<unsigned int>(childrenCount);

    for (unsigned int i = 0; i < childrenCount; ++i) {
        unsigned int childID;
        readAssetInfo(reader, childID);
        childrenVector.push_back(childID);
    }

    //a few more bytes of unknown data
}
