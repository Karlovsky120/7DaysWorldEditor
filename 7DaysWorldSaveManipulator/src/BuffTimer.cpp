#include "BuffTimer.h"

#include "BinaryMemoryReader.h"
#include "BinaryMemoryWriter.h"
#include "BuffTimerNull.h"
#include "BuffTimerDuration.h"
#include "BuffTimerScheduled.h"
#include "VersionCheck.h"

BuffTimer::BuffTimer() {}
BuffTimer::~BuffTimer() {}

BuffTimerClassId BuffTimer::getType() {
    return BuffTimerBase;
}

std::shared_ptr<BuffTimer> BuffTimer::instantiate(BuffTimerClassId id) {
    switch (id) {
        case Null:
            return std::make_shared<BuffTimerNull>();
        case Duration:
            return std::make_shared<BuffTimerDuration>();
        case Scheduled:
            return std::make_shared<BuffTimerScheduled>();
        default:
            return std::make_shared<BuffTimer>();
    }
}

std::shared_ptr<BuffTimer> BuffTimer::read(BinaryMemoryReader &reader) {
    int buffTimerVersion;
    reader.read<int>(buffTimerVersion);
    VersionCheck::checkVersion(buffTimerVersion, BUFF_TIMER_VER, BUFF_TIMER);

    unsigned char buffTimerClassId;
    reader.read<unsigned char>(buffTimerClassId);

    std::shared_ptr<BuffTimer> timer = instantiate((BuffTimerClassId)buffTimerClassId);
    timer->buffTimerVersion = buffTimerVersion;
    timer->buffTimerClassId = buffTimerClassId;
    timer->readMore(reader);

    return timer;
}

void BuffTimer::write(BinaryMemoryWriter &writer) const {
    writer.write<int>(buffTimerVersion);
    writer.write<unsigned char>(buffTimerClassId);
}

int BuffTimer::readMore(BinaryMemoryReader &reader) {
    return 0;
}
