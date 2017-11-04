#pragma once
#include "Buff.h"

#include <map>
#include <string>
#include <vector>

class BinaryMemoryReader;
class BinaryMemoryWriter;
class MultiBuffAction;
class MultiBuffPrefabAttachmentDescriptor;

class MultiBuff : public Buff {
public:
	int multiBuffVersion;
	std::string multiBuffClassId;

	std::vector<MultiBuffAction> multiBuffActionList;
	std::vector<MultiBuffAction> multiBuffActionList2;
	std::vector<MultiBuffPrefabAttachmentDescriptor> multiBuffPrefabAttachmentDescriptorList;

	std::map<std::string, float> buffCounterValues;

	BuffClassId getType() override;
	void write(BinaryMemoryWriter &writer, std::map<unsigned short, std::shared_ptr<StatModifier>> idTable) override;

	MultiBuff();
	~MultiBuff();

protected:
	int readMore(BinaryMemoryReader &reader, std::map<unsigned short, std::shared_ptr<StatModifier>> idTable) override;
};

