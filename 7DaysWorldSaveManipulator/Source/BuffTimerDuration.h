#pragma once
#include "DllHeader.h"

#include "BuffTimer.h"

class BinaryMemoryReader;
class BinaryMemoryWriter;

class SDWSM_API BuffTimerDuration : public BuffTimer {
public:
	float duration;
	float elapsed;

	BuffTimerClassId getType() override;
	void write(BinaryMemoryWriter &writer) const override;

	BuffTimerDuration();
	~BuffTimerDuration();

protected:
	int readMore(BinaryMemoryReader &reader) override;
};
