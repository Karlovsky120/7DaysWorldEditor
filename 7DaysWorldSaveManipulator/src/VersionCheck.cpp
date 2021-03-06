#include "VersionCheck.h"

VersionCheck::VersionCheck() {}
VersionCheck::~VersionCheck() {}

void VersionCheck::checkVersion(int readVersion, int expectedVersion, std::string objectName) {
    if (readVersion != expectedVersion) {
        throw std::runtime_error("Version of " + objectName + " was " + (char)readVersion + ", while the expected value was " + (char)expectedVersion + ".");
    }
}
