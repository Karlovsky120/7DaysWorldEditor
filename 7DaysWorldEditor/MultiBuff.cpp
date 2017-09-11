#include "MultiBuff.h"

#include "BinaryMemoryReader.h"
#include "MultiBuffAction.h"
#include "MultiBuffPrefabAttachmentDescriptor.h"

void MultiBuff::readMore(BinaryMemoryReader &reader, std::map<unsigned short, std::shared_ptr<StatModifier>> idTable) {
	Buff::readMore(reader, idTable);

	reader.read<int>(multiBuffVersion);
	reader.read<std::string>(multiBuffClassId);

	reader.readMultipleComplex<MultiBuffAction, int>(multiBuffActionList);
	reader.readMultipleComplex<MultiBuffAction, int>(multiBuffActionList2);

	reader.readMultipleComplex<MultiBuffPrefabAttachmentDescriptor, int>(multiBuffPrefabAttachmentDescriptorList);

	int buffCounterCounter;
	reader.read<int>(buffCounterCounter);

	for (int i = 0; i < buffCounterCounter; ++i) {
		std::string key;
		reader.read<std::string>(key);
		float value;
		reader.read<float>(value);

		buffCounterValues[key] = value;
	}
}

MultiBuff::MultiBuff() {}
MultiBuff::~MultiBuff() {}