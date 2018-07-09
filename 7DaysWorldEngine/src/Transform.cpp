#include "Transform.h"

#include "binaryIO/BinaryFileReader.h"

Transform::Transform() {}

Transform::~Transform() {}

void Transform::readAsset(BinaryFileReader &reader) {
    //unsigned int fileID - 0 is current file; It seems that I don't need it, so far
    reader.seek(4, seekEnum::cur);

    reader.read<unsigned int>(parentID);

    //unsigned int name, seems to always be 0
    reader.seek(4, seekEnum::cur);

    float p[3];

    //rotation
    for (int i = 0; i < 4; ++i) {
        reader.read<float>(p[i]);
    }

    transformation.setRotation(glm::angleAxis(p[3], glm::vec3(p[0], p[1], p[2])));

    //position
    for (int i = 0; i < 3; ++i) {
        reader.read<float>(p[i]);
    }

    transformation.setPosition(glm::vec3(p[0], p[1], p[2]));

    //scale
    for (int i = 0; i < 3; ++i) {
        reader.read<float>(p[i]);
    }

    transformation.setScale(glm::vec3(p[0], p[1], p[2]));

    unsigned int childrenCount;
    reader.read<unsigned int>(childrenCount);

    for (int i = 0; i < childrenCount; ++i) {
        //unsigned int fileID - 0 is current file; It seems that I don't need it, so far
        reader.seek(4, seekEnum::cur);

        unsigned int childIndex;
        reader.read<unsigned int>(childIndex);
        childrenVector.push_back(childIndex);

        //unsigned int name, seems to always be 0
        reader.seek(4, seekEnum::cur);
    }

    //3 more bytes of unknown data
}
