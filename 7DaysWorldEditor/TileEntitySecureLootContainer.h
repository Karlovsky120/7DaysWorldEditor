#pragma once

#include "TileEntityLootContainer.h"

#include <vector>

class BinaryMemoryReader;

class TileEntitySecureLootContainer : public TileEntityLootContainer
{
public:
	int *version;
	bool *md;
	bool *vd;
	std::string *gd;
	std::string *xd;

	std::vector<std::string *> kd;

	TileEntitySecureLootContainer *read(BinaryMemoryReader *const reader) override;

	TileEntitySecureLootContainer();
	~TileEntitySecureLootContainer();
};

