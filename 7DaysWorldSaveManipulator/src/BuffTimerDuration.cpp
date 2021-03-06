#include "BuffTimerDuration.h"

#include "BinaryMemoryReader.h"
#include "BinaryMemoryWriter.h"

BuffTimerDuration::BuffTimerDuration() {}
BuffTimerDuration::~BuffTimerDuration() {}

BuffTimerClassId BuffTimerDuration::getType() {
    return Duration;
}

void BuffTimerDuration::write(BinaryMemoryWriter &writer) const {
    BuffTimer::write(writer);

    writer.write<float>(elapsed);
    writer.write<float>(duration);
}

int BuffTimerDuration::readMore(BinaryMemoryReader &reader) {
    BuffTimer::readMore(reader);

    reader.read<float>(elapsed);
    reader.read<float>(duration);

    return 0;
}
