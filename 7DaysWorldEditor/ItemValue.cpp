#include "ItemValue.h"

#include "BinaryMemoryReader.h"
#include "BinaryMemoryWriter.h"

void ItemValue::read(BinaryMemoryReader &reader) {
	reader.read<unsigned char>(itemValueVersion);
	reader.read<unsigned short>(type);
	reader.read<unsigned short>(useTimes);
	reader.read<unsigned short>(quality);
	reader.read<unsigned short>(meta);

	unsigned char partNumber;
	reader.read<unsigned char>(partNumber);

	if (partNumber != 0) {
		for (int i = 0; i < partNumber; ++i) {
			bool exists;
			reader.read<bool>(exists);

			if (exists) {
				ItemValue part;
				part.read(reader);
				parts[i] = part;
			}
		}
	}

	bool hasAttachments;
	reader.read<bool>(hasAttachments);


	if (hasAttachments) {
		reader.readMultipleComplex<ItemValue, unsigned char>(attachments);
	}

	reader.read<bool>(activated);
	reader.read<unsigned char>(selectedAmmoTypeIndex);
}

void ItemValue::write(BinaryMemoryWriter &writer) const {
	writer.write<unsigned char>(itemValueVersion);
	writer.write<unsigned short>(type);
	writer.write<unsigned short>(useTimes);
	writer.write<unsigned short>(quality);
	writer.write<unsigned short>(meta);

#pragma warning (suppress: 4267)
	writer.writeConst<unsigned char>(parts.size());

	if (0 != parts.size()) {
		for (int i = 0; i < parts.size(); ++i) {
			bool exists = parts.find(i) != parts.end();
			writer.write<bool>(exists);

			if (exists) {
				ItemValue part;
				part.write(writer);
			}
		}
	}

	bool hasAttachments = attachments.size() > 0;
	writer.write<bool>(hasAttachments);

	if (hasAttachments) {
		writer.writeMultipleComplex<ItemValue, unsigned char>(attachments);
	}

	writer.write<bool>(activated);
	writer.write<unsigned char>(selectedAmmoTypeIndex);
}

ItemValue::ItemValue() {}
ItemValue::~ItemValue() {}
