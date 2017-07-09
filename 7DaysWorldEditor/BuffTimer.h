#pragma once

class BinaryMemoryReader;

enum BuffTimerClassId {
	Null,
	Duration,
	Scheduled
};

class BuffTimer
{
public:
	int *buffTimerVersion;
	unsigned char *buffTimerClassId;

	BuffTimer *read(BinaryMemoryReader *const reader);
	static BuffTimer *instantiate(BuffTimerClassId id);

	BuffTimer();
	~BuffTimer();

private:
	void readMore(BinaryMemoryReader *const reader);
};

