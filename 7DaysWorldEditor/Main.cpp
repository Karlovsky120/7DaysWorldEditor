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

int main(int argc, char* argv[])
{
	std::string argv_str(argv[0]);
	currentDirectory = argv_str.substr(0, argv_str.find_last_of("\\")) + "\\";
	

	//Initialize main log
	log4cplus::Initializer initializer;
	log4cplus::PropertyConfigurator::doConfigure("log4cplus.ini");

	mainLog = log4cplus::Logger::getInstance(LOG4CPLUS_TEXT("mainLog"));
	LOG4CPLUS_INFO(mainLog, LOG4CPLUS_TEXT("Execution started!"));
	
	for (int k = -2; k < 10; k++) {

		int a = 5;

		for (int l = -10; l < 10; l++) {
			RegionFile region(currentDirectory + "Dummy152b8\\Region", k, l); //-4 //-3

			if (region.timeStamps.capacity() > 0) {
				region.write(currentDirectory + "Dummy15.2b8");
				Chunk *chunk = new Chunk();

				for (int i = 0; i < 32; ++i) {

					int  h = 5;

					for (int j = 0; j < 32; ++j) {
						region.getChunk(*chunk, i, j);
					}
				}
			}
		}
	}
}