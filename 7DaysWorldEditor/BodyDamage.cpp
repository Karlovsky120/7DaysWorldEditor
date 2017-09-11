#include "BodyDamage.h"

#include "BinaryMemoryReader.h"

void BodyDamage::read(BinaryMemoryReader &reader) {
	reader.read<int>(bodyDamageVersion);

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
}

BodyDamage::BodyDamage() {}
BodyDamage::~BodyDamage() {}
