#pragma once
#include "DllHeader.h"

#include "BuffTimer.h"

class BinaryMemoryReader;
class BinaryMemoryWriter;

class SDWSM_API BuffTimerScheduled : public BuffTimer {
public:
	int buffTimerScheduledVersion;
	unsigned _int64 unknownG;
	int duration;
	float unknownE;
	int elapsed;

	BuffTimerClassId getType() override;
	void write(BinaryMemoryWriter &writer) const override;

	BuffTimerScheduled();
	~BuffTimerScheduled();

protected:
	int readMore(BinaryMemoryReader &reader) override;
};
