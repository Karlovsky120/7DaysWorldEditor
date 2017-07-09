#pragma once

#include <vector>

class BinaryMemoryReader;

class ItemValue
{
public:
	bool *activated;
	std::vector<ItemValue*> attachments;
	unsigned char *itemValueVersion;
	unsigned short *meta;
	std::vector<ItemValue*> parts;
	unsigned short *quality;
	unsigned char *selectedAmmoTypeIndex;
	unsigned short *type;
	unsigned short *useTimes;

	ItemValue *read(BinaryMemoryReader *const reader);

	ItemValue();
	~ItemValue();
};

