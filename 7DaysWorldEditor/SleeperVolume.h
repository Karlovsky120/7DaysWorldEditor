#pragma once

#include "Coordinate.h"

#include <map>
#include <string>
#include <vector>

class BinaryMemoryReader;
class SpawnPoint;

class SleeperVolume {
public:
	unsigned char sleeperVolumeVersion;
	std::string qj;
	Coordinate<int> mins;
	Coordinate<int> maxs;
	unsigned _int64 bj;
	unsigned _int64 gj;
	int pj;
	int tj;
	int uj;

	std::string ij;
	int xj;
	bool yj;
	bool lj;

	std::vector<SpawnPoint> dj;

	std::vector<unsigned char> fj;
	std::vector<int> aj;

	std::map<int, std::string> jj;
	std::vector<int> rj;

	void read(BinaryMemoryReader &reader);

	SleeperVolume();
	~SleeperVolume();
};

