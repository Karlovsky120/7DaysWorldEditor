#include "BinaryMemoryWriter.h"

#include "zipUnzip\Zip.h"

#include <fstream>

extern std::string currentDirectory;

BinaryMemoryWriter::BinaryMemoryWriter(int reservedBytes) {
    unzippedData.resize(reservedBytes);
}

BinaryMemoryWriter::~BinaryMemoryWriter() {}

void BinaryMemoryWriter::fetchZipped(std::vector<unsigned char> &zipped) {
    unzippedData.resize(position);

    /*#pragma warning(suppress: 4267)
        HZIP hz = CreateZip(0, unzippedData.size(), nullptr);

    #pragma warning(suppress: 4267)
        ZRESULT result = ZipAdd(hz, "test", &unzippedData[0], unzippedData.size());
        CloseZip(hz);

        if (result != ZR_OK) {
            throw std::ios_base::failure(errorMsg);
        }*/
}

void BinaryMemoryWriter::fetchUnzipped(std::vector<unsigned char> &unzipped) {
    unzippedData.resize(position);
    unzipped = unzippedData;
}
