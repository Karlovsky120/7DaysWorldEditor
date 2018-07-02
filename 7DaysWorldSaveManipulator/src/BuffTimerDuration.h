#pragma once

#include "BuffTimer.h"

class BinaryMemoryReader;
class BinaryMemoryWriter;

class BuffTimerDuration : public BuffTimer {
public:
    float duration;
    float elapsed;

    BuffTimerDuration();
    ~BuffTimerDuration();

    BuffTimerClassId getType() override;
    void write(BinaryMemoryWriter &writer) const override;

protected:
    int readMore(BinaryMemoryReader &reader) override;
};
