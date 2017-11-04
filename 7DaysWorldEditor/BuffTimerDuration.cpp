#include "BuffTimerDuration.h"

#include "BinaryMemoryReader.h"
#include "BinaryMemoryWriter.h"

BuffTimerClassId BuffTimerDuration::getType() {
	return Duration;
}

void BuffTimerDuration::write(BinaryMemoryWriter &writer) const {
	BuffTimer::write(writer);

	writer.write<float>(elapsed);
	writer.write<float>(duration);
}

int BuffTimerDuration::readMore(BinaryMemoryReader &reader) {
	CHECK_VERSION_ZERO(BuffTimer::readMore(reader));

	reader.read<float>(elapsed);
	reader.read<float>(duration);

	return 0;
}

BuffTimerDuration::BuffTimerDuration() {}
BuffTimerDuration::~BuffTimerDuration() {}