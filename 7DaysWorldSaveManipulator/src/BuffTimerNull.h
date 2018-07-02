#pragma once

#include "BuffTimer.h"

class BuffTimerNull : public BuffTimer {
public:
    BuffTimerNull();
    ~BuffTimerNull();

    BuffTimerClassId getType() override;
};
