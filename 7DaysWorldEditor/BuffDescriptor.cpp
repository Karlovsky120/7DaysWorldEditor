#include "BuffDescriptor.h"

#include "BinaryMemoryReader.h"

void BuffDescriptor::read(BinaryMemoryReader &reader) {
	reader.read<int>(buffDescriptorVersion);
	reader.read<int>(categoryFlags);
	reader.read<std::string>(notificationClass);

	reader.readMultipleSimple<std::string, int>(overrides);
}

BuffDescriptor::BuffDescriptor() {}
BuffDescriptor::~BuffDescriptor() {}