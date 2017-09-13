#pragma once
#include "TileEntityLootContainer.h"

#include <string>
#include <vector>

class BinaryMemoryReader;

class TileEntitySecureLootContainer : public TileEntityLootContainer {
public:
	int version;
	bool md;
	bool vd;
	std::string gd;
	std::string xd;

	std::vector<std::string> kd;

	void read(BinaryMemoryReader &reader) override;

	TileEntitySecureLootContainer();
	~TileEntitySecureLootContainer();
};

