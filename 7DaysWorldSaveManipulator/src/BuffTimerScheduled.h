#pragma once

#include "BuffTimer.h"

class BinaryMemoryReader;
class BinaryMemoryWriter;

class BuffTimerScheduled : public BuffTimer {
public:
    int buffTimerScheduledVersion;
    unsigned _int64 unknownG;
    int duration;
    float unknownE;
    int elapsed;

    BuffTimerScheduled();
    ~BuffTimerScheduled();

    BuffTimerClassId getType() override;
    void write(BinaryMemoryWriter &writer) const override;

protected:
    int readMore(BinaryMemoryReader &reader) override;
};
