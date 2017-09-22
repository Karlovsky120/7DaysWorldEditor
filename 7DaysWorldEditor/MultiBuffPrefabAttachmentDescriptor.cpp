#include "MultiBuffPrefabAttachmentDescriptor.h"

#include "BinaryMemoryReader.h"
#include "BinaryMemoryWriter.h"

void MultiBuffPrefabAttachmentDescriptor::read(BinaryMemoryReader &reader) {
	reader.read<int>(multiBuffPrefabAttachmentDescriptorVersion);
	reader.read<std::string>(prefabName);
	reader.read<std::string>(transformPath);
	reader.read<float>(TTL);
	reader.read<bool>(firstPerson);
	reader.read<bool>(thirdPerson);
}

void MultiBuffPrefabAttachmentDescriptor::write(BinaryMemoryWriter &writer) const {
	writer.write<int>(multiBuffPrefabAttachmentDescriptorVersion);
	writer.write<std::string>(prefabName);
	writer.write<std::string>(transformPath);
	writer.write<float>(TTL);
	writer.write<bool>(firstPerson);
	writer.write<bool>(thirdPerson);
}

MultiBuffPrefabAttachmentDescriptor::MultiBuffPrefabAttachmentDescriptor() {}
MultiBuffPrefabAttachmentDescriptor::~MultiBuffPrefabAttachmentDescriptor() {}