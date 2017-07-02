#include "BodyDamage.h"

#include "BinaryMemoryReader.h"


void BodyDamage::read(BinaryMemoryReader &reader) {
	reader.readInt32(&bodyDamageVersion);

	reader.readInt16(&leftUpperLeg);
	reader.readInt16(&rightUpperLeg);
	reader.readInt16(&leftUpperArm);
	reader.readInt16(&rightUpperArm);
	reader.readInt16(&chest);
	reader.readInt16(&head);

	reader.readBoolean(&dismemberedLeftUpperArm);
	reader.readBoolean(&dismemberedRightUpperArm);
	reader.readBoolean(&dismemberedHead);
	reader.readBoolean(&dismemberedRightUpperLeg);
	reader.readBoolean(&crippledRightLeg);

	reader.readInt16(&leftLowerLeg);
	reader.readInt16(&rightLowerLeg);
	reader.readInt16(&leftLowerArm);
	reader.readInt16(&rightLowerArm);

	reader.readBoolean(&dismemberedLeftLowerArm);
	reader.readBoolean(&dismemberedRightLowerArm);
	reader.readBoolean(&dismemberedLeftLowerArm);
	reader.readBoolean(&dismemberedRightLowerArm);

	reader.readBoolean(&dismemberedLeftUpperLeg);
	reader.readBoolean(&crippledLeftLeg);
}

BodyDamage::BodyDamage() {}


BodyDamage::~BodyDamage() {}
