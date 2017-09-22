#include "BinaryMemoryReader.h"

#include "PreprocessorConfig.h"

#include <log4cplus/logger.h>
#include <log4cplus/loggingmacros.h>

#include <fstream>

extern log4cplus::Logger mainLog;
extern std::string currentDirectory;

bool BinaryMemoryReader::initialize(std::vector<unsigned char> &zipped) {
	ZIPENTRY ze;
	ZRESULT result;

#if READTOFILE
	// The 8 bytes is a header which is already read.
#pragma warning(suppress: 4267)
	hz = OpenZip(&zipped[8], zipped.capacity() - 8, 0);
	result = GetZipItem(hz, 0, &ze);

	if (result != ZR_OK) {
		LOG4CPLUS_ERROR(mainLog, LOG4CPLUS_TEXT("Failed to open zip file within the region file."));

		CloseZip(hz);
		return false;
	}

	std::vector<unsigned char> unzipped = std::vector<unsigned char>(1000000);

#pragma warning(suppress: 4267)
	result = UnzipItem(hz, 0, &unzipped[0], unzipped.size());
	CloseZip(hz);

	if (result == ZR_OK) {
		unzipped.resize(ze.unc_size);
		length = ze.unc_size;

		std::fstream bout(currentDirectory + "chunk.read.hex", std::ios::out | std::ios::binary);
		bout.write((char *)&unzipped[0], unzipped.size());
		bout.close();
	}
#endif

	// Those 8 bytes are metadata we no longer need.
#pragma warning(suppress: 4267) // Conversion from size_t to unsigned int - file will never be that large
	hz = OpenZip(&zipped[8], zipped.capacity() - 8, 0);

	result = GetZipItem(hz, 0, &ze);

	if (result != ZR_OK) {
		LOG4CPLUS_ERROR(mainLog, LOG4CPLUS_TEXT("Failed to open zip file within the region file."));

		CloseZip(hz);
		return false;
	}

	return true;
}

BinaryMemoryReader::BinaryMemoryReader() {}

BinaryMemoryReader::~BinaryMemoryReader() {
	CloseZip(hz);
}
