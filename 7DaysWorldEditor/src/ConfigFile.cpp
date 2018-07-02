#include "configFile.h"

#include <wx\log.h>

bool ConfigFile::open(std::string configFilePath) {
	path = configFilePath;
	std::ifstream cFile;
	cFile.open(path, std::ios::binary | std::ios::in);

	if (cFile.good()) {
		std::string line;

		while (std::getline(cFile, line)) {
			if (line.find('#') != 0 && line.find('\n') != 0 && line.find('\r') != 0) {
				line = line.substr(0, line.length() - 1);
				int pos = line.find('=');

				std::string propertyName = line.substr(0, pos);
				std::string propertyValue = line.substr(pos + 1, line.length());

				properties[propertyName] = propertyValue;

				/*int propertyValue;

				try {
					propertyValue = std::stoi(valueString);
				} catch (std::exception e) {
					propertyValue = INT_MIN;
					LOGW << "Failed to read property " + propertyName + "." + e.what();
					return false;
				}

				properties[propertyName] = propertyValue;*/
			}
		}

		return true;
	}
	else {
		std::string errorMsg = "Failed to open config file at " + path + ".";
		wxLogError(errorMsg.c_str());
		return false;
	}
}

void ConfigFile::save() {
	std::ofstream cFile;
	cFile.open(path, std::ios::binary | std::ios::out);

	if (cFile.good()) {
		for (auto const &prop : properties) {
			cFile << prop.first << "=" << prop.second;
		}
	}
}

bool ConfigFile::getProperty(std::string propertyName, std::string &value) const {
	if (auto it = properties.find(propertyName) != properties.end()) {
		value = properties.find(propertyName)->second;
		return true;
	}
	else {
		std::string errorMsg = "Could not find " + propertyName + ".";
		wxLogError(errorMsg.c_str());
		return false;
	}
}

bool ConfigFile::getProperty(std::string propertyName, int &value) const {
	if (auto it = properties.find(propertyName) != properties.end()) {
		try {
			value = std::stoi(properties.find(propertyName)->second);
		}
		catch (std::exception e) {
			std::string errorMsg = "Failed to read property " + propertyName + ". " + e.what();
			wxLogError(errorMsg.c_str());
			return false;
		}
		return true;
	}
	else {
		std::string errorMsg = "Could not find " + propertyName + ".";
		wxLogError(errorMsg.c_str());
		return false;
	}
}

bool ConfigFile::setProperty(std::string propertyName, std::string &value) {
	if (auto it = properties.find(propertyName) != properties.end()) {
		properties.find(propertyName)->second = value;
		return true;
	}
	else {
		properties[propertyName] = value;
		return false;
	}
}

bool ConfigFile::setProperty(std::string propertyName, int &value) {
	if (auto it = properties.find(propertyName) != properties.end()) {
		properties.find(propertyName)->second = value;
		return true;
	}
	else {
		properties[propertyName] = value;
		return false;
	}
}

ConfigFile::ConfigFile() {}
ConfigFile::~ConfigFile() {}
