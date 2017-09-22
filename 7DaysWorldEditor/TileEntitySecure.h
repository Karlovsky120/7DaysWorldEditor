#pragma once
#include "TileEntityLootContainer.h"

#include <string>
#include <vector>

class BinaryMemeoryReader;
class BinaryMemoryWriter;

class TileEntitySecure : public TileEntityLootContainer {
public:
	int version;
	bool md;
	bool vd;
	std::string gd;
	std::vector<std::string> kd;
	std::string xd;

	TileEntityClassId getType() override;
	void read(BinaryMemoryReader &reader) override;
	void write(BinaryMemoryWriter &writer) override;

	TileEntitySecure();
	~TileEntitySecure();
};