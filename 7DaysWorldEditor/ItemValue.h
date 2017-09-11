#pragma once

#include <map>
#include <vector>

class BinaryMemoryReader;

class ItemValue
{
public:
	bool activated;

	std::vector<ItemValue> attachments;

	unsigned char itemValueVersion;
	unsigned short meta;

	std::map<unsigned int, ItemValue> parts;

	unsigned short quality;
	unsigned char selectedAmmoTypeIndex;
	unsigned short type;
	unsigned short useTimes;

	void read(BinaryMemoryReader &reader);

	ItemValue();
	~ItemValue();
};

