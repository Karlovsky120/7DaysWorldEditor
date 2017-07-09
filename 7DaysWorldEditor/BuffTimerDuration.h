#pragma once

#include "BuffTimer.h"

class BinaryMemoryReader;

class BuffTimerDuration : public BuffTimer
{
public:
	float *duration;
	float *elapsed;

	BuffTimerDuration();
	~BuffTimerDuration();

private:
	BuffTimerDuration *readMore(BinaryMemoryReader *const reader);
};

