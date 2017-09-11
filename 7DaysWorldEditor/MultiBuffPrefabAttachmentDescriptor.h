#pragma once

#include <string>

class BinaryMemoryReader;

class MultiBuffPrefabAttachmentDescriptor
{
public:
	int multiBuffPrefabAttachmentDescriptorVersion;
	std::string prefabName;
	std::string transformPath;
	float TTL;
	bool firstPerson;
	bool thirdPerson;

	void read(BinaryMemoryReader &reader);

	MultiBuffPrefabAttachmentDescriptor();
	~MultiBuffPrefabAttachmentDescriptor();
};