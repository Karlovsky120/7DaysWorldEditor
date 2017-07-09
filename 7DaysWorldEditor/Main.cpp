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
	
	RegionFile region(currentDirectory + "Dummy152b8\\Region", -4, -3);

	region.write(currentDirectory + "Dummy15.2b8");
	Chunk *chunk = new Chunk();
	region.getChunk(*chunk, 16, 16);
}