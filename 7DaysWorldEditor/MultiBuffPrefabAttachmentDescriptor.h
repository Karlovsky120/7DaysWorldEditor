#pragma once
#include "VersionCheck.h"

#include <string>

class BinaryMemoryReader;
class BinaryMemoryWriter;

class MultiBuffPrefabAttachmentDescriptor : public VersionCheck {
public:
	int multiBuffPrefabAttachmentDescriptorVersion;
	std::string prefabName;
	std::string transformPath;
	float TTL;
	bool firstPerson;
	bool thirdPerson;

	int read(BinaryMemoryReader &reader);
	void write(BinaryMemoryWriter &writer) const;

	MultiBuffPrefabAttachmentDescriptor();
	~MultiBuffPrefabAttachmentDescriptor();
};