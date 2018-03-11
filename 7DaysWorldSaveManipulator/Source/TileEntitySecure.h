#pragma once
#include "DllHeader.h"

#include "TileEntityLootContainer.h"

#include <string>
#include <vector>

class BinaryMemeoryReader;
class BinaryMemoryWriter;

class SDWSM_API TileEntitySecure : public TileEntityLootContainer {
public:
	int version;
	bool md;
	bool vd;
	std::string gd;
	std::vector<std::string> kd;
	std::string xd;

	TileEntityClassId getType() override;
	int read(BinaryMemoryReader &reader) override;
	void write(BinaryMemoryWriter &writer) const override;

	TileEntitySecure();
	~TileEntitySecure();
};
