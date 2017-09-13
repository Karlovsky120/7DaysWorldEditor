#include "ItemValue.h"

#include "BinaryMemoryReader.h"

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

ItemValue::ItemValue() {}
ItemValue::~ItemValue() {}
