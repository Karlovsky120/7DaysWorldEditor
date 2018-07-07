#pragma once

#include <string>


class AssetExtractor
{
public:
	AssetExtractor();
	~AssetExtractor();

private:
	std::string address = "C:\\Programs\\Steam\\steamapps\\common\\7 Days To Die\\7DaysToDie_Data\\resources.assets";

	void extract();
};

