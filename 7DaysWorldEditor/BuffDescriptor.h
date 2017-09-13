#pragma once
#include <string>
#include <vector>

class BinaryMemoryReader;

class BuffDescriptor {
public:
	int buffDescriptorVersion;
	int categoryFlags;
	std::string notificationClass;
	std::vector<std::string> overrides;

	void read(BinaryMemoryReader &reader);

	BuffDescriptor();
	~BuffDescriptor();
};

