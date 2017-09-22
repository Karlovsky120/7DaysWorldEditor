#pragma once
#include "TileEntitySecure.h"

class TileEntitySecureDoor : public TileEntitySecure {
public:
	TileEntityClassId getType() override;

	TileEntitySecureDoor();
	~TileEntitySecureDoor();
};

