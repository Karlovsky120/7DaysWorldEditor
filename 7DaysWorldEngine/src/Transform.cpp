#include "Transform.h"

#include "binaryIO/BinaryFileReader.h"

Transform::Transform() {}

Transform::~Transform() {}

void Transform::readAsset(BinaryFileReader &reader) {
    //unsigned int fileID - 0 is current file; It seems that I don't need it, so far
    reader.seek(4);

    reader.read<unsigned int>(parentID);

    //unsigned int name, seems to always be 0
    reader.seek(4);

    float coords[4];

    //rotation
    for (int i = 0; i < 4; ++i) {
        reader.read<float>(coords[i]);
    }

    transformation.setRotation(glm::angleAxis(coords[3], glm::vec3(coords[0], coords[1], coords[2])));

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
        //unsigned int fileID - 0 is current file; It seems that I don't need it, so far
        reader.seek(4);

        unsigned int childIndex;
        reader.read<unsigned int>(childIndex);
        childrenVector.push_back(childIndex);

        //unsigned int name, seems to always be 0
        reader.seek(4);
    }

    //a few more bytes of unknown data
}
