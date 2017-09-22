#pragma once
#include <string>
#include <vector>

class BinaryMemoryReader;
class BinaryMemoryWriter;

class BuffDescriptor {
public:
	int buffDescriptorVersion;
	int categoryFlags;
	std::string notificationClass;
	std::vector<std::string> overrides;

	void read(BinaryMemoryReader &reader);
	void write(BinaryMemoryWriter &write);

	BuffDescriptor();
	~BuffDescriptor();
};

