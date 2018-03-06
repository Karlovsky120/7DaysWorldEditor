#include "BinaryMemoryReader.h"

#include "MemoryLeakManager.h"

#include "wx\log.h"

void BinaryMemoryReader::unzipWhole(std::vector<unsigned char> &zipped, std::vector<unsigned char> &unzipped) {
#pragma warning(suppress: 4267)
	HZIP hz = OpenZip(&zipped[8], zipped.capacity() - 8, 0);
	ZIPENTRY ze;
	ZRESULT result = GetZipItem(hz, 0, &ze);

	if (ZR_OK == result) {
		unzipped = std::vector<unsigned char>(ze.unc_size);

#pragma warning(suppress: 4267)
		result = UnzipItem(hz, 0, &unzipped[0], unzipped.size());
	}

	if (result != ZR_OK) {
		std::string errorMsg = "Failed to unzip zipped chunk.";
		wxLogError(errorMsg.c_str());

		CloseZip(hz);
		throw std::ios_base::failure(errorMsg);
	}
}

BinaryMemoryReader::BinaryMemoryReader(std::vector<unsigned char> &zipped) {
	// The 8 bytes is a header which is already read.
#pragma warning(suppress: 4267) // Conversion from size_t to unsigned int - file will never be that large
	hz = OpenZip(&zipped[8], zipped.capacity() - 8, 0);
	ZIPENTRY ze;
	ZRESULT result = GetZipItem(hz, 0, &ze);
	length = ze.unc_size;

	if (result != ZR_OK) {
		std::string errorMsg = "Failed to unzip chunk within the region file.";
		wxLogError(errorMsg.c_str());

		CloseZip(hz);
		throw std::ios_base::failure(errorMsg);
	}
}

BinaryMemoryReader::~BinaryMemoryReader() {
	CloseZip(hz);
	MemoryLeakManager::freeMemoryLeaks();
}
