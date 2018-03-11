#pragma once
#include "DllHeader.h"

#include <map>
#include <vector>

class BinaryMemoryReader;
class BinaryMemoryWriter;

class SDWSM_API ItemValue {
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

	int read(BinaryMemoryReader &reader);
	void write(BinaryMemoryWriter &writer) const;

	ItemValue();
	~ItemValue();
};
