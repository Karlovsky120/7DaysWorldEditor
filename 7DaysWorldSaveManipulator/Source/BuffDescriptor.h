#pragma once
#include "DllHeader.h"

#include <string>
#include <vector>

class BinaryMemoryReader;
class BinaryMemoryWriter;

class SDWSM_API BuffDescriptor {
public:
	int buffDescriptorVersion;
	int categoryFlags;
	std::string notificationClass;
	std::vector<std::string> overrides;

	int read(BinaryMemoryReader &reader);
	void write(BinaryMemoryWriter &write) const;

	BuffDescriptor();
	~BuffDescriptor();
};
