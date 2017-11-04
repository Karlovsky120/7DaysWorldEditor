#include "Chunk.h"
#include "RegionFile.h"

#include "ConfigFile.h"

#include <log4cplus/configurator.h>
#include <log4cplus/fileappender.h>
#include <log4cplus/initializer.h>
#include <log4cplus/layout.h>
#include <log4cplus/logger.h>
#include <log4cplus/loggingmacros.h>

#include <experimental/filesystem>

#include <fstream>
#include <string>

log4cplus::Logger mainLog;
ConfigFile saveVersion;
std::string currentDirectory;

int main(int argc, char* argv[]) {

	std::string argv_str(argv[0]);
	currentDirectory = argv_str.substr(0, argv_str.find_last_of("\\")) + "\\";

	std::experimental::filesystem::create_directory("logs");

	log4cplus::Initializer initializer;
	log4cplus::PropertyConfigurator::doConfigure("cfg\\log4cplus.ini");

	mainLog = log4cplus::Logger::getInstance(LOG4CPLUS_TEXT("mainLog"));
	LOG4CPLUS_INFO(mainLog, LOG4CPLUS_TEXT("Execution started!"));

	//Load save version config
	saveVersion.open(currentDirectory + "cfg\\currentVersion.ini");






	//TEST CODE

	for (int k = -4; k < -1; k++) {

		for (int l = -3; l < 1; ++l) {
			RegionFile regionFile(currentDirectory + "A16.3b12\\Region", k, l);

			if (regionFile.timeStamps.capacity() > 0) {
				regionFile.write(currentDirectory + "A16.3b12\\data");
				for (int i = 0; i < 32; ++i) {

					for (int j = 0; j < 32; ++j) {
						if (regionFile.chunkExists(i, j)) {

							//if (k == -3 && l == -3 && i == 11 && j == 5) {
								Chunk chunk = Chunk();
								bool success = regionFile.readChunk(chunk, i, j);

								if (success) {
									regionFile.writeChunk(chunk, i, j);
								}
								int a = 0;

								std::fstream binR(currentDirectory + "chunk.read.hex", std::ios::in | std::ios::binary);
								std::fstream binW(currentDirectory + "chunk.write.hex", std::ios::in | std::ios::binary);

								unsigned char *r = new unsigned char(1000000);
								unsigned char *w = new unsigned char(1000000);

								binR.write((char *)&r[0], 1000000);
								binW.write((char *)&r[0], 1000000);

								bool flag = false;

								for (int k = 0; k < 1000000; ++k) {
									flag = *r != *w;
								}

								if (flag) {
									int g = 0;
								}

								binR.close();
								binW.close();
							//}
						}
					}
				}
			}
		}
	}

	//END TEST CODE

	LOG4CPLUS_INFO(mainLog, LOG4CPLUS_TEXT("Execution complete!\n\n"));

	return 0;
}