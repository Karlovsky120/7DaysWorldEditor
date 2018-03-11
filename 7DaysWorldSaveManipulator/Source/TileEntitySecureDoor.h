#pragma once
#include "DllHeader.h"

#include "TileEntitySecure.h"

class SDWSM_API TileEntitySecureDoor : public TileEntitySecure {
public:
	TileEntityClassId getType() override;

	TileEntitySecureDoor();
	~TileEntitySecureDoor();
};
