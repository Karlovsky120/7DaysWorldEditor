#include "BuffTimerScheduled.h"

#include "BinaryMemoryReader.h"
#include "BinaryMemoryWriter.h"

BuffTimerClassId BuffTimerScheduled::getType() {
	return Scheduled;
}

void BuffTimerScheduled::write(BinaryMemoryWriter &writer) const {
	BuffTimer::write(writer);

	writer.write<int>(buffTimerScheduledVersion);

	writer.write<unsigned _int64>(unknownG);
	writer.write<int>(duration);
	writer.write<float>(unknownE);
	writer.write<int>(elapsed);
}

int BuffTimerScheduled::readMore(BinaryMemoryReader &reader) {
	CHECK_VERSION_ZERO(BuffTimer::readMore(reader));

	reader.read<int>(buffTimerScheduledVersion);
	CHECK_VERSION(buffTimerScheduledVersion, BUFF_TIMER_SCHEDULED);

	reader.read<unsigned _int64>(unknownG);
	reader.read<int>(duration);
	reader.read<float>(unknownE);
	reader.read<int>(elapsed);

	return 0;
}

BuffTimerScheduled::BuffTimerScheduled() {}
BuffTimerScheduled::~BuffTimerScheduled() {}