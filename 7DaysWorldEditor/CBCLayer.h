#pragma once

class BinaryMemoryReader;

class CBCLayer
{
public:
	void Read(BinaryMemoryReader &Reader);

	CBCLayer();
	~CBCLayer();
};

