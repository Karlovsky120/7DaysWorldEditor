#pragma once

#include "TileEntityLootContainer.h"

#include <vector>

class BinaryMemeoryReader;

class TileEntitySecure : public TileEntityLootContainer
{
public:
	int version;
	bool md;
	bool vd;
	std::string gd;
	std::vector<std::string> kd;
	std::string xd;

	void read(BinaryMemoryReader &reader) override;

	TileEntitySecure();
	~TileEntitySecure();
};