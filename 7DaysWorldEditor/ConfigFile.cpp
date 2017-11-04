#include "configFile.h"

#include "Log4cplus.h"

bool ConfigFile::open(std::string configFilePath) {
	cFile.open(configFilePath, std::ios::binary | std::ios::out);

	if (cFile.good()) {
		std::string line;

		while (std::getline(cFile, line)) {
			if (line.find('#') != 0 && line.find('\n') != 0 && line.find('\r') != 0) {
				line = line.substr(0, line.length() - 1);
				int pos = line.find('=');

				std::string propertyName = line.substr(0, pos);
				std::string valueString = line.substr(pos + 1, line.length());
				int propertyValue;

				try {
					propertyValue = std::stoi(valueString);
				} catch (std::exception e) {
					propertyValue = INT_MIN;
					std::string errorString = "Failed to read property " + propertyName + "." + e.what();
					LOG4CPLUS_WARN(mainLog, LOG4CPLUS_TEXT(errorString));
					return false;
				}

				properties[propertyName] = propertyValue;
			}
		}

		return true;
	} else {
		std::string errorString = "Failed to open config file at " + configFilePath + ".";
		LOG4CPLUS_WARN(mainLog, LOG4CPLUS_TEXT(errorString));
		return false;
	}
}

bool ConfigFile::getProperty(std::string propertyName, int &value) {
	if (auto it = properties.find(propertyName) != properties.end()) {
		value = properties.find(propertyName)->second;
		return true;
	} else {
		std::string errorString = "Could not find " + propertyName + ".";
		LOG4CPLUS_WARN(mainLog, LOG4CPLUS_TEXT(errorString));
		return false;
	}
}


ConfigFile::ConfigFile() {}
ConfigFile::~ConfigFile() {}
