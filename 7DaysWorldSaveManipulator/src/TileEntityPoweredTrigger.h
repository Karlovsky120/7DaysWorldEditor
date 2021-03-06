#pragma once

#include "TileEntityPowered.h"

#include <string>

class BinaryMemoryReader;
class BinaryMemoryWriter;

enum TriggerTypes {
    Switch,
    PressurePlateTrigger,
    TimerRelay,
    Motion,
    TripWire
};

class TileEntityPoweredTrigger : public TileEntityPowered {
public:
    unsigned char triggerType;
    std::string lrz;
    bool showTriggerOptions;
    unsigned char property1;
    unsigned char property2;
    int targetType;

    TileEntityPoweredTrigger();
    ~TileEntityPoweredTrigger();

    TileEntityClassId getType() const override;
    int read(BinaryMemoryReader &reader) override;
    void write(BinaryMemoryWriter &writer) const override;
};
