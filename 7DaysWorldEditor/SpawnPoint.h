#pragma once
#include "Coordinate.h"

class BinaryMemoryReader;

class SpawnPoint {
public:
	Coordinate<int> pos;
	Coordinate<float> look;

	float rot;
	unsigned char pose;
	unsigned short blockID;

	void read(BinaryMemoryReader &reader);

	SpawnPoint();
	~SpawnPoint();
};

