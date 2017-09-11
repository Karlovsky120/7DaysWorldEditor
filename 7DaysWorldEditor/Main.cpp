#include <log4cplus/configurator.h>
#include <log4cplus/fileappender.h>
#include <log4cplus/initializer.h>
#include <log4cplus/layout.h>
#include <log4cplus/logger.h>
#include <log4cplus/loggingmacros.h>

#include "RegionFile.h"
#include "Chunk.h"

log4cplus::Logger mainLog;
std::string currentDirectory;

int main(int argc, char* argv[]) {

	std::string argv_str(argv[0]);
	currentDirectory = argv_str.substr(0, argv_str.find_last_of("\\")) + "\\";
	

	//Initialize main log
	log4cplus::Initializer initializer;
	log4cplus::PropertyConfigurator::doConfigure("log4cplus.ini");

	mainLog = log4cplus::Logger::getInstance(LOG4CPLUS_TEXT("mainLog"));
	LOG4CPLUS_INFO(mainLog, LOG4CPLUS_TEXT("Execution started!"));
	

	/*RegionFile region(currentDirectory + "Dummy152b8\\Region", -2, -3);
	Chunk *chunk = new Chunk();
	region.getChunk(*chunk, 11, 10);*/

	for (int k = -4; k < -1; k++) {

		for (int l = -3; l < 1; ++l) {
			RegionFile regionFile(currentDirectory + "A16.1b1\\Region", k, l);

			if (regionFile.timeStamps.capacity() > 0) {
				regionFile.write(currentDirectory + "A16.1b1\\data");
				for (int i = 0; i < 32; ++i) {

					for (int j = 0; j < 32; ++j) {
						if (regionFile.chunkExists(i, j)) {

							if (k == -4 && l == -1 && i == 25 && j == 10) {
								Chunk chunk = Chunk();
								regionFile.getChunk(chunk, i, j);
							}
						}
					}
				}
			}
		}
	}
}