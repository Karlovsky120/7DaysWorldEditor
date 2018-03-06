#pragma once
#include "BuffTimer.h"

class BuffTimerNull : public BuffTimer {
public:
	BuffTimerClassId getType() override;

	BuffTimerNull();
	~BuffTimerNull();
};
