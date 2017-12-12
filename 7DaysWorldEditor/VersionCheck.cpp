#include "VersionCheck.h"

#include "ConfigFile.h"

#include "wx\log.h"

extern ConfigFile saveVersion;

int VersionCheck::checkVersion(int readVersion, std::string objectName) {
	int expectedVersion;
	saveVersion.getProperty(objectName, expectedVersion);
	if (readVersion != expectedVersion) {
    std::string errorMsg = "Version mismatch! Expected " + std::to_string(expectedVersion) + ", read " + std::to_string(readVersion) + " for " + objectName;
    wxLogError(errorMsg.c_str());

		// Return a negative value of read version if the read version is older than the expected version.
		return expectedVersion > readVersion ? -readVersion : readVersion;
	}

	return 0;
}

VersionCheck::VersionCheck() {}
VersionCheck::~VersionCheck() {}