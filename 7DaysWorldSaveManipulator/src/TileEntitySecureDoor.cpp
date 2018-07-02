#include "TileEntitySecureDoor.h"

TileEntitySecureDoor::TileEntitySecureDoor() {}
TileEntitySecureDoor::~TileEntitySecureDoor() {}

TileEntityClassId TileEntitySecureDoor::getType() const {
    return SecureDoor;
}
