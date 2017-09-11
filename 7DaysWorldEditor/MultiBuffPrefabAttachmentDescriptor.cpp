#include "MultiBuffPrefabAttachmentDescriptor.h"

#include "BinaryMemoryReader.h"

void MultiBuffPrefabAttachmentDescriptor::read(BinaryMemoryReader &reader) {
	reader.read<int>(multiBuffPrefabAttachmentDescriptorVersion);
	reader.read<std::string>(prefabName);
	reader.read<std::string>(transformPath);
	reader.read<float>(TTL);
	reader.read<bool>(firstPerson);
	reader.read<bool>(thirdPerson);
}

MultiBuffPrefabAttachmentDescriptor::MultiBuffPrefabAttachmentDescriptor() {}
MultiBuffPrefabAttachmentDescriptor::~MultiBuffPrefabAttachmentDescriptor() {}