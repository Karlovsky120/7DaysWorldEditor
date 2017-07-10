#include "BuffTimer.h"

#include "BinaryMemoryReader.h"
#include "BuffTimerNull.h"
#include "BuffTimerDuration.h"
#include "BuffTimerScheduled.h"

BuffTimer * BuffTimer::read(BinaryMemoryReader * const reader) {
	int *buffTimerVersion;
	reader->read<int>(&buffTimerVersion);
	unsigned char *buffTimerClassId;
	reader->read<unsigned char>(&buffTimerClassId);

	BuffTimer *timer = new BuffTimer();
	timer->buffTimerVersion = buffTimerVersion;
	timer->buffTimerClassId = buffTimerClassId;
	timer->readMore(reader);

	return timer;
}

BuffTimer * BuffTimer::instantiate(BuffTimerClassId id)
{
	switch (id) {
		case Null:
			return new BuffTimerNull();
		case Duration:
			return new BuffTimerDuration();
		case Scheduled:
			return new BuffTimerScheduled();
	}

	return new BuffTimer();
}

void BuffTimer::readMore(BinaryMemoryReader * const reader) {}

BuffTimer::BuffTimer() {}
BuffTimer::~BuffTimer() {}