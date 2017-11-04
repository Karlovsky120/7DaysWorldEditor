#pragma once
#include "BuffTimer.h"

class BinaryMemoryReader;
class BinaryMemoryWriter;

class BuffTimerDuration : public BuffTimer {
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

