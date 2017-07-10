#include "MultiBuffPrefabAttachmentDescriptor.h"

#include "BinaryMemoryReader.h"

MultiBuffPrefabAttachmentDescriptor *MultiBuffPrefabAttachmentDescriptor::read(BinaryMemoryReader *const reader) {
	reader->read<int>(&multiBuffPrefabAttachmentDescriptorVersion);
	reader->read<std::string>(&prefabName);
	reader->read<std::string>(&transformPath);
	reader->read<float>(&TTL);
	reader->read<bool>(&firstPerson);
	reader->read<bool>(&thirdPerson);

	return this;
}

MultiBuffPrefabAttachmentDescriptor::MultiBuffPrefabAttachmentDescriptor() {}
MultiBuffPrefabAttachmentDescriptor::~MultiBuffPrefabAttachmentDescriptor() {}