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

void BuffTimerDuration::readMore(BinaryMemoryReader &reader) {
	BuffTimer::readMore(reader);

	reader.read<float>(elapsed);
	reader.read<float>(duration);
}

BuffTimerDuration::BuffTimerDuration() {}
BuffTimerDuration::~BuffTimerDuration() {}