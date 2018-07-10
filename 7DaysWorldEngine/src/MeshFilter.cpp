#include "MeshFilter.h"

#include "binaryIO/BinaryFileReader.h"

MeshFilter::MeshFilter() {}

MeshFilter::~MeshFilter() {}

void MeshFilter::readAsset(BinaryFileReader &reader) {
    //unsigned int parent fileID
    reader.seek(4);
    reader.read<unsigned int>(parentID);

    //unsigned int unknown
    //unsigned int child fileID
    reader.seek(8);
    unsigned int childID;
    reader.read<unsigned int>(childID);
    childrenVector.push_back(childID);

    //unsigned int unknown
}
