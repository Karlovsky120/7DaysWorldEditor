#include "BuffDescriptor.h"

#include "BinaryMemoryReader.h"
#include "BinaryMemoryWriter.h"

void BuffDescriptor::read(BinaryMemoryReader &reader) {
	reader.read<int>(buffDescriptorVersion);
	reader.read<int>(categoryFlags);
	reader.read<std::string>(notificationClass);

	reader.readMultipleSimple<std::string, int>(overrides);
}

void BuffDescriptor::write(BinaryMemoryWriter &writer) {
	writer.write<int>(buffDescriptorVersion);
	writer.write<int>(categoryFlags);
	writer.write<std::string>(notificationClass);

	writer.writeMultipleSimple<std::string, int>(overrides);
}

BuffDescriptor::BuffDescriptor() {}
BuffDescriptor::~BuffDescriptor() {}