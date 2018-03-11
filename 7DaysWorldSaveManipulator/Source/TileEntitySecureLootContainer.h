#pragma once
#include "DllHeader.h"

#include "TileEntityLootContainer.h"

#include <string>
#include <vector>

class BinaryMemoryReader;
class BinaryMemoryWriter;

class SDWSM_API TileEntitySecureLootContainer : public TileEntityLootContainer {
public:
	int version;
	bool md;
	bool vd;
	std::string gd;
	std::string xd;

	std::vector<std::string> kd;

	TileEntityClassId getType() override;
	int read(BinaryMemoryReader &reader) override;
	void write(BinaryMemoryWriter &writer) const override;

	TileEntitySecureLootContainer();
	~TileEntitySecureLootContainer();
};
