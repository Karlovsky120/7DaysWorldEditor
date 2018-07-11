#include "MeshFilter.h"

#include "binaryIO/BinaryFileReader.h"

MeshFilter::MeshFilter() {}

MeshFilter::~MeshFilter() {}

void MeshFilter::readAsset(BinaryFileReader &reader) {
    readAssetInfo(reader, parentID);

    unsigned int childID;
    readAssetInfo(reader, childID);
    childrenVector.push_back(childID);
}
