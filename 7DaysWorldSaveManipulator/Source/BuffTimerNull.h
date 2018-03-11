#pragma once
#include "DllHeader.h"

#include "BuffTimer.h"

class SDWSM_API BuffTimerNull : public BuffTimer {
public:
	BuffTimerClassId getType() override;

	BuffTimerNull();
	~BuffTimerNull();
};
