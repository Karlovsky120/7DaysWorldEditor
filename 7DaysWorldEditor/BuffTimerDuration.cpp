#include "BuffTimerDuration.h"

#include "BinaryMemoryReader.h"

BuffTimerDuration *BuffTimerDuration::readMore(BinaryMemoryReader *const reader) {
	BuffTimer::read(reader);
	reader->read<float>(&elapsed);
	reader->read<float>(&duration);
	return this;
}

BuffTimerDuration::BuffTimerDuration() {}
BuffTimerDuration::~BuffTimerDuration() {}