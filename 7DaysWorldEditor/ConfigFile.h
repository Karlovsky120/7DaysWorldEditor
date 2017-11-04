#pragma once

#include <fstream>
#include <istream>
#include <string>
#include <map>

class ConfigFile {
public:
	bool open(std::string configFilePath);
	bool getProperty(std::string propertyName, int &value);

	ConfigFile();
	~ConfigFile();

private:
	std::ifstream cFile;
	std::map<std::string, int> properties;
};

