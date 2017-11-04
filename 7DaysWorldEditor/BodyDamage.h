#pragma once
#include "SaveVersionCheck.h"

class BinaryMemoryReader;
class BinaryMemoryWriter;

class BodyDamage : public SaveVersionCheck {
public:
	int bodyDamageVersion;

	short chest;
	bool crippledLeftLeg;
	bool crippledRightLeg;
	bool dismemberedHead;
	bool dismemberedLeftLowerArm;
	bool dismemberedLeftLowerLeg;
	bool dismemberedLeftUpperArm;
	bool dismemberedLeftUpperLeg;
	bool dismemberedRightLowerArm;
	bool dismemberedRightLowerLeg;
	bool dismemberedRightUpperArm;
	bool dismemberedRightUpperLeg;
	short head;
	short leftLowerArm;
	short leftLowerLeg;
	short leftUpperArm;
	short leftUpperLeg;
	short rightLowerArm;
	short rightLowerLeg;
	short rightUpperArm;
	short rightUpperLeg;

	int read(BinaryMemoryReader &reader);
	void write(BinaryMemoryWriter &writer) const;

	BodyDamage();
	~BodyDamage();
};

