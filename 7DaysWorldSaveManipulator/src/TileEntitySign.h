#pragma once

#include "TileEntity.h"

#include <string>
#include <vector>

class BinaryMemoryReader;
class BinaryMemoryWriter;

class TileEntitySign : public TileEntity {
public:
	int  version;

	bool vd;
	std::string gd;
	std::string xd;

	std::vector<std::string> kd;

	std::string signText;

	TileEntitySign();
	~TileEntitySign();

	TileEntityClassId getType() const override;
	int read(BinaryMemoryReader &reader) override;
	void write(BinaryMemoryWriter &writer) const override;
};
