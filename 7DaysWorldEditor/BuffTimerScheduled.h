#pragma once

#include "BuffTimer.h"

class BinaryMemoryReader;

class BuffTimerScheduled : public BuffTimer
{
public:
	int buffTimerScheduledVersion;
	unsigned _int64 unknownG;
	int duration;
	float unknownE;
	int elapsed;

	BuffTimerScheduled();
	~BuffTimerScheduled();

protected:
	void readMore(BinaryMemoryReader &reader) override;
};
