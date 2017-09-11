#include "BinaryMemoryReader.h"

#include <log4cplus/logger.h>
#include <log4cplus/loggingmacros.h>

#include <fstream>

extern log4cplus::Logger mainLog;
extern std::string currentDirectory;

BinaryMemoryReader::BinaryMemoryReader(std::vector<unsigned char> &zipped) {
	std::fstream bin(currentDirectory + "chunk.zip", std::ios::out | std::ios::binary);
	bin.write((char *)&zipped[8], zipped.capacity() - 8);
	bin.close();

	// The 8 bytes is a header I've already read.
	hz = OpenZip(&zipped[8], zipped.capacity() - 8, 0);

	ZIPENTRY ze;
	ZRESULT result = GetZipItem(hz, 0, &ze);

	if (result != ZR_OK) {
		LOG4CPLUS_ERROR(mainLog, LOG4CPLUS_TEXT("Failed to open zip file within the region file."));

		CloseZip(hz);
	}
	

	std::vector<unsigned char> unzipped = std::vector<unsigned char>(1000000);

	#pragma warning(suppress: 4267) // Conversion from size_t to unsigned int - file will never be that large
	result = UnzipItem(hz, 0, &unzipped[0], unzipped.size());
	CloseZip(hz);

	if (result == ZR_OK) {
		unzipped.resize(ze.unc_size);
		length = ze.unc_size;

		{ //DEBUG
			std::fstream bout(currentDirectory + "chunk.hex", std::ios::out | std::ios::binary);
			bout.write((char *)&unzipped[0], unzipped.size());
			bout.close();
		}
	}

	// Those 8 bytes are metadata we no longer need.
	#pragma warning(suppress: 4267) // Conversion from size_t to unsigned int - file will never be that large
	hz = OpenZip(&zipped[8], zipped.capacity() - 8, 0);

	//ZIPENTRY ze;
	/*ZRESULT*/ result = GetZipItem(hz, 0, &ze);

	if (result != ZR_OK) {
		LOG4CPLUS_ERROR(mainLog, LOG4CPLUS_TEXT("Failed to open zip file within the region file."));

		CloseZip(hz);
	}
}

BinaryMemoryReader::BinaryMemoryReader() {}

BinaryMemoryReader::~BinaryMemoryReader() {
	CloseZip(hz);
}
