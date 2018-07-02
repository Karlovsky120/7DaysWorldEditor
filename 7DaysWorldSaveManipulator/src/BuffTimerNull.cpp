#include "BuffTimerNull.h"

BuffTimerNull::BuffTimerNull() {}
BuffTimerNull::~BuffTimerNull() {}

BuffTimerClassId BuffTimerNull::getType() {
    return Null;
}
