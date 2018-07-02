#pragma once

#include <string>
#include <vector>

class BinaryMemoryReader;
class BinaryMemoryWriter;

class ChunkCustomData {
public:
    std::string key;
    unsigned _int64 expiresInWorldTime;
    bool isSavedToNetwork;

    std::vector<unsigned char> data;

    ChunkCustomData();
    ~ChunkCustomData();

    int read(BinaryMemoryReader &reader);
    void write(BinaryMemoryWriter &writer) const;
};
