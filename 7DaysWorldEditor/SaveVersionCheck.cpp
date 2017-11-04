#include "SaveVersionCheck.h"

#include "ConfigFile.h"

#include "Log4cplus.h"

extern ConfigFile saveVersion;

int SaveVersionCheck::checkVersion(int readVersion, std::string objectName) {
	int expectedVersion;
	saveVersion.getProperty(objectName, expectedVersion);
	if (readVersion != expectedVersion) {
		std::string errorMsg = "Version mismatch! Expected " + std::to_string(expectedVersion) + ", read " + std::to_string(readVersion) + " for " + objectName;
		LOG4CPLUS_ERROR(mainLog, LOG4CPLUS_TEXT(errorMsg));

		// Return a negative value of read version if the read version is older than the expected version.
		return expectedVersion > readVersion ? -readVersion : readVersion;
	}

	return 0;
}

SaveVersionCheck::SaveVersionCheck() {}
SaveVersionCheck::~SaveVersionCheck() {}