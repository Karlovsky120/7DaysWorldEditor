#pragma once

#include "VersionCheck.h"

#include <vector>

class BinaryMemoryWriter;
class Chunk;

class RegionFile {
public:
    int rX;
    int rZ;

    std::vector<std::vector<unsigned char>> zippedChunks;

    RegionFile(const std::string path, const int rX, const int rZ);
    RegionFile(std::string path);
    RegionFile(std::vector<int> timeStamps, std::vector<std::vector<unsigned char>> zippedChunks);
    ~RegionFile();

    // Chunk managment
    inline bool chunkExists(const int rcX, const int rcZ) const;
    inline bool chunkExists(const int position) const;
    int readChunk(Chunk &chunk, const int position);
    inline int readChunk(Chunk &chunk, const int rcX, const int rcZ);
    void writeChunk(const Chunk &chunk, const int position);
    inline void writeChunk(const Chunk &chunk, const int rcX, const int rcZ);
    void writeChunk(const Chunk &chunk, BinaryMemoryWriter &writer, const int position);

private:
    std::vector<int> timeStamps;

    // Region file managment
    void read(const std::string path);
    inline void write(std::string path, const int rX, const int rZ);
    void write(const std::string path);
};
