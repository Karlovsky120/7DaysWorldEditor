#include "BinaryMemoryWriter.h"

#include "PreprocessorConfig.h"
#include "Zip.h"

#include <fstream>

extern std::string currentDirectory;

void BinaryMemoryWriter::fetchZipped(std::vector<unsigned char> &zipped) {
	unzippedData.resize(position);

/*#pragma warning(suppress: 4267)
	HZIP hz = CreateZip(0, unzippedData.size(), nullptr);

#pragma warning(suppress: 4267)	
	ZRESULT result = ZipAdd(hz, "test", &unzippedData[0], unzippedData.size());
	CloseZip(hz);

	if (result != ZR_OK) {
		std::string errorMsg = "Failed to zip chunk.";
		LOGE << errorMsg;

		throw std::ios_base::failure(errorMsg);
	}*/
}

void BinaryMemoryWriter::fetchUnzipped(std::vector<unsigned char> &unzipped) {
	unzippedData.resize(position);
	unzipped = unzippedData;
}

BinaryMemoryWriter::BinaryMemoryWriter(int reservedBytes) {
	unzippedData.resize(reservedBytes);
}

BinaryMemoryWriter::~BinaryMemoryWriter() {}
