#pragma once
#include "DllHeader.h"

#include <string>

class BinaryMemoryReader;
class BinaryMemoryWriter;

class SDWSM_API MultiBuffPrefabAttachmentDescriptor {
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
