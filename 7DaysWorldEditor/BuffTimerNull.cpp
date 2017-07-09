#include "BuffTimerNull.h"

BuffTimerNull *BuffTimerNull::readMore(BinaryMemoryReader * const reader) {
	return this;
}

BuffTimerNull::BuffTimerNull() {}
BuffTimerNull::~BuffTimerNull() {}