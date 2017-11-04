#include "BodyDamage.h"

#include "BinaryMemoryReader.h"
#include "BinaryMemoryWriter.h"

int BodyDamage::read(BinaryMemoryReader &reader) {
	reader.read<int>(bodyDamageVersion);
	CHECK_VERSION(bodyDamageVersion, BODY_DAMAGE);

	reader.read<short>(leftUpperLeg);
	reader.read<short>(rightUpperLeg);
	reader.read<short>(leftUpperArm);
	reader.read<short>(rightUpperArm);
	reader.read<short>(chest);
	reader.read<short>(head);

	reader.read<bool>(dismemberedLeftUpperArm);
	reader.read<bool>(dismemberedRightUpperArm);
	reader.read<bool>(dismemberedHead);
	reader.read<bool>(dismemberedRightUpperLeg);
	reader.read<bool>(crippledRightLeg);

	reader.read<short>(leftLowerLeg);
	reader.read<short>(rightLowerLeg);
	reader.read<short>(leftLowerArm);
	reader.read<short>(rightLowerArm);

	reader.read<bool>(dismemberedLeftLowerArm);
	reader.read<bool>(dismemberedRightLowerArm);
	reader.read<bool>(dismemberedLeftLowerLeg);
	reader.read<bool>(dismemberedRightLowerLeg);

	reader.read<bool>(dismemberedLeftUpperLeg);
	reader.read<bool>(crippledLeftLeg);

	return 0;
}

void BodyDamage::write(BinaryMemoryWriter &writer) const {
	writer.write<int>(bodyDamageVersion);

	writer.write<short>(leftUpperLeg);
	writer.write<short>(rightUpperLeg);
	writer.write<short>(leftUpperArm);
	writer.write<short>(rightUpperArm);
	writer.write<short>(chest);
	writer.write<short>(head);

	writer.write<bool>(dismemberedLeftUpperArm);
	writer.write<bool>(dismemberedRightUpperArm);
	writer.write<bool>(dismemberedHead);
	writer.write<bool>(dismemberedRightUpperLeg);
	writer.write<bool>(crippledRightLeg);

	writer.write<short>(leftLowerLeg);
	writer.write<short>(rightLowerLeg);
	writer.write<short>(leftLowerArm);
	writer.write<short>(rightLowerArm);

	writer.write<bool>(dismemberedLeftLowerArm);
	writer.write<bool>(dismemberedRightLowerArm);
	writer.write<bool>(dismemberedLeftLowerLeg);
	writer.write<bool>(dismemberedRightLowerLeg);

	writer.write<bool>(dismemberedLeftUpperLeg);
	writer.write<bool>(crippledLeftLeg);
}

BodyDamage::BodyDamage() {}
BodyDamage::~BodyDamage() {}
