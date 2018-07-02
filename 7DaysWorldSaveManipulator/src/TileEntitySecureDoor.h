#pragma once

#include "TileEntitySecure.h"

class TileEntitySecureDoor : public TileEntitySecure {
public:
    TileEntitySecureDoor();
    ~TileEntitySecureDoor();

    TileEntityClassId getType() const override;
};
