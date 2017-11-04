#pragma once
#include "VersionCheck.h"

#include <memory>

class BinaryMemoryReader;
class BinaryMemoryWriter;

enum BuffTimerClassId {
	Null,
	Duration,
	Scheduled,
	BuffTimerBase
};

class BuffTimer : public VersionCheck{
public:
	int buffTimerVersion;
	unsigned char buffTimerClassId;

	virtual BuffTimerClassId getType();
	static std::shared_ptr<BuffTimer> instantiate(BuffTimerClassId id);
	static std::shared_ptr<BuffTimer> read(BinaryMemoryReader &reader, int &buffTimerVer);
	virtual void write(BinaryMemoryWriter &writer) const;

	BuffTimer();
	~BuffTimer();

protected:
	virtual int readMore(BinaryMemoryReader &reader);
};

