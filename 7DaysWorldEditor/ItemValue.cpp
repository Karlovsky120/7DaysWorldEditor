#include "ItemValue.h"

#include "BinaryMemoryReader.h"

ItemValue *ItemValue::read(BinaryMemoryReader *const reader)
{
	reader->read<unsigned char>(&itemValueVersion);
	reader->read<unsigned short>(&type);
	reader->read<unsigned short>(&useTimes);
	reader->read<unsigned short>(&quality);
	reader->read<unsigned short>(&meta);

	unsigned char *partNumber;
	reader->read<unsigned char>(&partNumber);

	if (partNumber != 0) {
		for (int i = 0; i < *partNumber; ++i) {
			bool *exists;
			reader->read<bool>(&exists);

			if (*exists) {
				ItemValue *part = new ItemValue();
				part->read(reader);
				parts.push_back(part);
			} else {
				parts.push_back(nullptr);
			}
		}
	}

	bool *hasAttachments;
	reader->read<bool>(&hasAttachments);

	if (*hasAttachments) {
		unsigned char *attachmentNum;
		reader->read<unsigned char>(&attachmentNum);

		for (int j = 0; j < *attachmentNum; ++j) {
			ItemValue *attachment = new ItemValue();
			attachment->read(reader);
			attachments.push_back(attachment);
		}
	}

	reader->read<bool>(&activated);
	reader->read<unsigned char>(&selectedAmmoTypeIndex);

	return this;
}

ItemValue::ItemValue() {}
ItemValue::~ItemValue() {}
