#pragma once

#include <memory>

class BinaryMemoryReader;
class BinaryMemoryWriter;

enum BuffTimerClassId {
    Null,
    Duration,
    Scheduled,
    BuffTimerBase
};

class BuffTimer {
public:
    int buffTimerVersion;
    unsigned char buffTimerClassId;

    BuffTimer();
    ~BuffTimer();

    virtual BuffTimerClassId getType();
    static std::shared_ptr<BuffTimer> instantiate(BuffTimerClassId id);
    static std::shared_ptr<BuffTimer> read(BinaryMemoryReader &reader);
    virtual void write(BinaryMemoryWriter &writer) const;

protected:
    virtual int readMore(BinaryMemoryReader &reader);
};
