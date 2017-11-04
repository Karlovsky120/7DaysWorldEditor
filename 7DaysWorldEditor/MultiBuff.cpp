#include "MultiBuff.h"

#include "BinaryMemoryReader.h"
#include "BinaryMemoryWriter.h"
#include "MultiBuffAction.h"
#include "MultiBuffPrefabAttachmentDescriptor.h"

BuffClassId MultiBuff::getType() {
	return MultiBuffType;
}

void MultiBuff::write(BinaryMemoryWriter &writer, std::map<unsigned short, std::shared_ptr<StatModifier>> idTable) {
	Buff::write(writer, idTable);

	writer.write<int>(multiBuffVersion);
	writer.write<std::string>(multiBuffClassId);

	writer.writeMultipleComplex<MultiBuffAction, int>(multiBuffActionList);
	writer.writeMultipleComplex<MultiBuffAction, int>(multiBuffActionList2);

	writer.writeMultipleComplex<MultiBuffPrefabAttachmentDescriptor, int>(multiBuffPrefabAttachmentDescriptorList);

#pragma warning (suppress: 4267)
	writer.writeConst<int>(buffCounterValues.size());

	for (auto buffCounterValue: buffCounterValues) {
		writer.writeConst<std::string>(buffCounterValue.first);

	}
}

int MultiBuff::readMore(BinaryMemoryReader &reader, std::map<unsigned short, std::shared_ptr<StatModifier>> idTable) {
	CHECK_VERSION_ZERO(Buff::readMore(reader, idTable));

	reader.read<int>(multiBuffVersion);
	CHECK_VERSION(multiBuffVersion, MULTI_BUFF);

	reader.read<std::string>(multiBuffClassId);

	CHECK_VERSION_ZERO((reader.readMultipleComplex<MultiBuffAction, int>(multiBuffActionList, MULTI_BUFF_ACTION)));
	CHECK_VERSION_ZERO((reader.readMultipleComplex<MultiBuffAction, int>(multiBuffActionList2, MULTI_BUFF_ACTION)));

	CHECK_VERSION_ZERO((reader.readMultipleComplex<MultiBuffPrefabAttachmentDescriptor, int>(multiBuffPrefabAttachmentDescriptorList, MULTI_BUFF_PREFAB_ATTACHMENT_DESCRIPTOR)));

	int buffCounterCounter;
	reader.read<int>(buffCounterCounter);

	for (int i = 0; i < buffCounterCounter; ++i) {
		std::string key;
		reader.read<std::string>(key);
		float value;
		reader.read<float>(value);

		buffCounterValues[key] = value;
	}

	return 0;
}

MultiBuff::MultiBuff() {}
MultiBuff::~MultiBuff() {}