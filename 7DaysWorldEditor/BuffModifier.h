#pragma once
#include <memory>

class BinaryMemoryReader;

enum BuffModifierClassId {
	BuffModifierSetTickRateEnum
};

class BuffModifier {
public:
	int UID;

	int buffModifierVersion;
	unsigned char buffModifierClassId;

	static std::shared_ptr<BuffModifier> read(BinaryMemoryReader &reader);
	static std::shared_ptr<BuffModifier> instantiate(BuffModifierClassId id);

	BuffModifier();
	~BuffModifier();

protected:
	virtual void readMore(BinaryMemoryReader &reader);
};

