#pragma once

#include "TileEntity.h"

#include <string>
#include <vector>

class BinaryMemoryReader;

class TileEntitySign : public TileEntity
{
public:
	int  version;

	bool vd;
	std::string gd;
	std::string xd;

	std::vector<std::string> kd;

	std::string signText;

	void read(BinaryMemoryReader &reader) override;

	TileEntitySign();
	~TileEntitySign();
};

