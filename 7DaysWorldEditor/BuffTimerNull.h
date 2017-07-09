#pragma once

#include "BuffTimer.h"

class BinaryMemoryReader;

class BuffTimerNull : public BuffTimer
{
public:
	BuffTimerNull();
	~BuffTimerNull();

private:
	BuffTimerNull *readMore(BinaryMemoryReader *const reader);
};