#pragma once

#include "TileEntityLootContainer.h"

#include <string>
#include <vector>

class BinaryMemoryReader;
class BinaryMemoryWriter;

class TileEntitySecureLootContainer : public TileEntityLootContainer {
public:
	int version;
	bool md;
	bool vd;
	std::string gd;
	std::string xd;
	std::vector<std::string> kd;

	TileEntitySecureLootContainer();
	~TileEntitySecureLootContainer();

	TileEntityClassId getType() const override;
	int read(BinaryMemoryReader &reader) override;
	void write(BinaryMemoryWriter &writer) const override;
};
