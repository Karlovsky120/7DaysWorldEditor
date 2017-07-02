#include <log4cplus/logger.h>
#include <log4cplus/loggingmacros.h>
#include <log4cplus/configurator.h>
#include <log4cplus/initializer.h>

#include "RegionFile.h"
#include "Chunk.h"

int main()
{
	log4cplus::Initializer initializer;

	log4cplus::BasicConfigurator config;
	config.configure();

	log4cplus::Logger logger = log4cplus::Logger::getInstance(LOG4CPLUS_TEXT("main"));
	LOG4CPLUS_INFO(logger, LOG4CPLUS_TEXT("Execution started!"));

	RegionFile region("C:\\Users\\Karlovsky120\\Documents\\Visual Studio 2015\\Projects\\7DaysWorldEditor\\Test data\\Dummy15.2b8\\Region", 1, 0);

	Chunk *chunk = new Chunk();
	region.getChunk(*chunk, 16, 16);
	delete chunk;
	region.write("C:\\Users\\Karlovsky120\\Documents\\Visual Studio 2015\\Projects\\7DaysWorldEditor\\Test data\\Dummy15.2b8\\Region\\Stored");
}