#include "BuffTimerScheduled.h"

#include "BinaryMemoryReader.h"

void BuffTimerScheduled::readMore(BinaryMemoryReader &reader) {
	BuffTimer::readMore(reader);

	reader.read<int>(buffTimerScheduledVersion);

	reader.read<unsigned _int64>(unknownG);
	reader.read<int>(duration);
	reader.read<float>(unknownE);
	reader.read<int>(elapsed);
}

BuffTimerScheduled::BuffTimerScheduled() {}
BuffTimerScheduled::~BuffTimerScheduled() {}