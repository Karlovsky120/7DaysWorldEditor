#include "BuffTimer.h"

#include "BinaryMemoryReader.h"
#include "BuffTimerNull.h"
#include "BuffTimerDuration.h"
#include "BuffTimerScheduled.h"

#include <assert.h>

std::shared_ptr<BuffTimer> BuffTimer::read(BinaryMemoryReader &reader) {
	int buffTimerVersion;
	reader.read<int>(buffTimerVersion);
	unsigned char buffTimerClassId;
	reader.read<unsigned char>(buffTimerClassId);

	std::shared_ptr<BuffTimer> timer = instantiate((BuffTimerClassId)buffTimerClassId);
	timer->buffTimerVersion = buffTimerVersion;
	timer->buffTimerClassId = buffTimerClassId;
	timer->readMore(reader);

	return timer;
}

std::shared_ptr<BuffTimer> BuffTimer::instantiate(BuffTimerClassId id) {
	switch (id) {
		case Null:
		return std::make_shared<BuffTimerNull>();
		case Duration:
		return std::make_shared<BuffTimerDuration>();
		case Scheduled:
		return std::make_shared<BuffTimerScheduled>();
	}

	assert(true);
}

void BuffTimer::readMore(BinaryMemoryReader &reader) {}

BuffTimer::BuffTimer() {}
BuffTimer::~BuffTimer() {}