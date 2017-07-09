#include "BuffDescriptor.h"

#include "BinaryMemoryReader.h"


BuffDescriptor * BuffDescriptor::read(BinaryMemoryReader * const reader) {
	reader->read<int>(&buffDescriptorVersion);
	reader->read<int>(&categoryFlags);
	reader->read<std::string>(&notificationClass);

	int *overrideCount;
	reader->read<int>(&overrideCount);
	for (int i = 0; i < *overrideCount; ++i) {
		std::string *overrideString;
		reader->read<std::string>(&overrideString);
		overrides.push_back(overrideString);
	}

	return this;
}

BuffDescriptor::BuffDescriptor() {}
BuffDescriptor::~BuffDescriptor() {}