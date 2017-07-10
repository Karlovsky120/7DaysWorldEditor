#pragma once

#include "Buff.h"

#include <map>
#include <string>
#include <vector>

class BinaryMemoryReader;
class MultiBuffAction;
class MultiBuffPrefabAttachmentDescriptor;

class MultiBuff : public Buff
{
public:
	int *multiBuffVersion;
	std::string *multiBuffClassId;

	std::vector<MultiBuffAction *> multiBuffActionList;
	std::vector<MultiBuffAction *> multiBuffActionList2;
	std::vector<MultiBuffPrefabAttachmentDescriptor *> multiBuffPrefabAttachmentDescriptorList;

	std::map<std::string *, float *> buffCounterValues;

	void readMore(BinaryMemoryReader *const reader, std::map<unsigned short *, StatModifier *> idTable) override;

	MultiBuff();
	~MultiBuff();
};

