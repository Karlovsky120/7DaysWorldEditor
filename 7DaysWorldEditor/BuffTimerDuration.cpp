#include "BuffTimerDuration.h"

#include "BinaryMemoryReader.h"

void BuffTimerDuration::readMore(BinaryMemoryReader &reader) {
	BuffTimer::readMore(reader);

	reader.read<float>(elapsed);
	reader.read<float>(duration);
}

BuffTimerDuration::BuffTimerDuration() {}
BuffTimerDuration::~BuffTimerDuration() {}