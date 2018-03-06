#pragma once

#include <fstream>
#include <istream>
#include <string>
#include <map>

class ConfigFile {
public:
	bool open(std::string configFilePath);
	void save();

	bool getProperty(std::string propertyName, std::string &value) const;
	bool getProperty(std::string propertyName, int &value) const;
	bool setProperty(std::string propertyName, std::string &value);
	bool setProperty(std::string propertyName, int &value);

	ConfigFile();
	~ConfigFile();

private:
	std::string path;
	std::map<std::string, std::string> properties;
};
