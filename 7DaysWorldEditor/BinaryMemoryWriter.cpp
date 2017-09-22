#include "BinaryMemoryWriter.h"

#include "PreprocessorConfig.h"

#include "Zip.h"

#include <log4cplus/logger.h>
#include <log4cplus/loggingmacros.h>

#include <fstream>

extern log4cplus::Logger mainLog;
extern std::string currentDirectory;

bool BinaryMemoryWriter::finalize(std::vector<unsigned char> &zipped) {
#if WRITETOFILE
	std::fstream bout(currentDirectory + "chunk.write.hex", std::ios::out | std::ios::binary);
	bout.write((char *)&unzippedData[0], position);
	bout.close();
#endif

#pragma warning(suppress: 4267)
	HZIP hz = CreateZip(0, unzippedData.size(), nullptr);

#pragma warning(suppress: 4267)	
	ZRESULT result = ZipAdd(hz, "test", &unzippedData[0], unzippedData.size());

	CloseZip(hz);

	if (result != ZR_OK) {
		return false;
	}

	return true;
}

BinaryMemoryWriter::BinaryMemoryWriter(int reservedBytes) {
	unzippedData.resize(reservedBytes);
}
BinaryMemoryWriter::~BinaryMemoryWriter() {}
