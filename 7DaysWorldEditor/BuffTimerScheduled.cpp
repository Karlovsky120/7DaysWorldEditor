#include "BuffTimerScheduled.h"

#include "BinaryMemoryReader.h"

BuffTimerScheduled * BuffTimerScheduled::readMore(BinaryMemoryReader * const reader) {
	BuffTimer::read(reader);

	reader->read<int>(&buffTimerScheduledVersion);

	reader->read<unsigned _int64>(&unknownG);
	reader->read<int>(&duration);
	reader->read<float>(&unknownE);
	reader->read<int>(&elapsed);

	return this;
}

BuffTimerScheduled::BuffTimerScheduled() {}
BuffTimerScheduled::~BuffTimerScheduled() {}