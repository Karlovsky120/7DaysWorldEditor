#pragma once
#include <memory>

class BinaryMemoryReader;

enum BuffTimerClassId {
	Null,
	Duration,
	Scheduled
};

class BuffTimer {
public:
	int buffTimerVersion;
	unsigned char buffTimerClassId;

	static std::shared_ptr<BuffTimer> instantiate(BuffTimerClassId id);
	static std::shared_ptr<BuffTimer> read(BinaryMemoryReader &reader);

	BuffTimer();
	~BuffTimer();

protected:
	virtual void readMore(BinaryMemoryReader &reader);
};

