#pragma once

#include "BodyDamage.h"
#include "Coordinate.h"

class BodyDamage;

class BinaryMemoryReader;

class EntityCreationData {
public:
	unsigned char *entityCreationDataVersion;
	int *entityClass;

	int *id;
	float *lifetime;

	Coordinate<float> pos;
	Coordinate<float> rot;

	bool *onGround;

	BodyDamage bodyDamage;

	bool *isStatsNotNull;
	short *deathTime;

	void read(BinaryMemoryReader &reader);

	EntityCreationData();
	~EntityCreationData();
};

