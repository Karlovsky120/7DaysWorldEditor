#pragma once
#include "VersionCheck.h"

#include <string>
#include <vector>

class BinaryMemoryReader;
class BinaryMemoryWriter;

class BuffDescriptor : public VersionCheck {
public:
	int buffDescriptorVersion;
	int categoryFlags;
	std::string notificationClass;
	std::vector<std::string> overrides;

	int read(BinaryMemoryReader &reader);
	void write(BinaryMemoryWriter &write);

	BuffDescriptor();
	~BuffDescriptor();
};

