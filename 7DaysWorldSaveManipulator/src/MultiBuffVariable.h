#pragma once

#include "VersionCheck.h"

class BinaryMemoryReader;
class BinaryMemoryWriter;

class MultiBuffVariable {
public:
    int multiBuffVariableVersion;
    float unknownQ;
    float unknownJ;
    float unknownS;
    float unknownC;

    MultiBuffVariable();
    ~MultiBuffVariable();

    int read(BinaryMemoryReader &reader);
    void write(BinaryMemoryWriter &writer) const;
};
