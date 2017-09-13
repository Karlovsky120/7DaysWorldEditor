#pragma once
#include <vector>

class Chunk;

class RegionFile {
public:
	int rX;
	int rZ;

	std::vector<int> timeStamps;

	void read(std::string path, const int rX, const int rZ);
	void write(std::string path);

	bool chunkExists(const int rcX, const int rcZ);
	bool getChunk(Chunk &chunk, const int rcX, const int rcZ);

	RegionFile(const std::string path, const int rX, const int rZ);
	~RegionFile();

private:
	std::vector<std::vector<unsigned char>> zippedChunks;

	RegionFile();
};

