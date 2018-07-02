#include "MultiBuffPrefabAttachmentDescriptor.h"

#include "BinaryMemoryReader.h"
#include "BinaryMemoryWriter.h"
#include "VersionCheck.h"

MultiBuffPrefabAttachmentDescriptor::MultiBuffPrefabAttachmentDescriptor() {}
MultiBuffPrefabAttachmentDescriptor::~MultiBuffPrefabAttachmentDescriptor() {}

int MultiBuffPrefabAttachmentDescriptor::read(BinaryMemoryReader &reader) {
    reader.read<int>(multiBuffPrefabAttachmentDescriptorVersion);
    VersionCheck::checkVersion(multiBuffPrefabAttachmentDescriptorVersion, MULTI_BUFF_PREFAB_ATTACHMENT_DESCRIPTOR_VER, MULTI_BUFF_PREFAB_ATTACHMENT_DESCRIPTOR);

    reader.read<std::string>(prefabName);
    reader.read<std::string>(transformPath);
    reader.read<float>(TTL);
    reader.read<bool>(firstPerson);
    reader.read<bool>(thirdPerson);

    return 0;
}

void MultiBuffPrefabAttachmentDescriptor::write(BinaryMemoryWriter &writer) const {
    writer.write<int>(multiBuffPrefabAttachmentDescriptorVersion);
    writer.write<std::string>(prefabName);
    writer.write<std::string>(transformPath);
    writer.write<float>(TTL);
    writer.write<bool>(firstPerson);
    writer.write<bool>(thirdPerson);
}
