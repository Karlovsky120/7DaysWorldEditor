#include "RegionFile.h"

#include "BinaryMemoryReader.h"
#include "BinaryMemoryWriter.h"
#include "Chunk.h"
#include "MemoryLeakManager.h"
#include "VersionCheck.h"

#include "binaryIO\BinaryFileReader.h"
#include "binaryIO\BinaryFileWriter.h"

RegionFile::RegionFile(std::string path, const int rX, const int rZ) :
    rX(rX),
    rZ(rZ) {
    path = path.append("\\r." + std::to_string(rX) + "." + std::to_string(rZ) + ".7rg");

    read(path);
}

RegionFile::RegionFile(const std::string path) {
    std::string name = path.substr(path.find_last_of('\\') + 1, path.length());
    if (name.length() > 3 && name.substr(name.length() - 3, name.length() - 1) == "7rg") {
        std::string coords = name.substr(name.find_first_of('.') + 1, name.find_last_of('.') - 2);

        rX = std::stoi(coords.substr(0, coords.find('.')));
        rZ = std::stoi(coords.substr(coords.find('.') + 1, coords.length()));

        read(path);
    }
}

RegionFile::RegionFile(std::vector<int> timeStamps, std::vector<std::vector<unsigned char>> zippedChunks) :
    timeStamps(timeStamps),
    zippedChunks(zippedChunks) {}

RegionFile::~RegionFile() {}

inline bool RegionFile::chunkExists(const int rcX, const int rcZ) const {
    return chunkExists(rcX + 32 * rcZ);
}

inline bool RegionFile::chunkExists(const int position) const {
    return zippedChunks[position].size() > 0;
}

int RegionFile::readChunk(Chunk &chunk, const int position) {
    if (!chunkExists(position)) {
        return INT_MAX;
    } else {
        memcpy(&chunk.header[0], &zippedChunks[position][0], 4);
        memcpy(&chunk.version, &zippedChunks[position][4], 4);

        VersionCheck::checkVersion(chunk.version, CHUNK_VER, CHUNK);

        BinaryMemoryReader reader = BinaryMemoryReader(zippedChunks[position]);
        bool isValidRead;
        chunk.read(reader, isValidRead);

        return isValidRead ? 0 : INT_MIN;
    }
}

inline int RegionFile::readChunk(Chunk &chunk, const int rcX, const int rcZ) {
    return readChunk(chunk, rcX + 32 * rcZ);
}

void RegionFile::writeChunk(const Chunk &chunk, const int position) {
    memcpy(&zippedChunks[position][0], &chunk.header[0], 4);
    memcpy(&zippedChunks[position][4], &chunk.version, 4);

    BinaryMemoryWriter writer = BinaryMemoryWriter(1000000); // 1MB
    chunk.write(writer);
    writer.fetchZipped(zippedChunks[position]);
}

inline void RegionFile::writeChunk(const Chunk &chunk, const int rcX, const int rcZ) {
    return writeChunk(chunk, rcX + 32 * rcZ);
}

void RegionFile::writeChunk(const Chunk &chunk, BinaryMemoryWriter &writer, const int position) {
    memcpy(&zippedChunks[position][0], &chunk.header[0], 4);
    memcpy(&zippedChunks[position][4], &chunk.version, 4);

    chunk.write(writer);
}

void RegionFile::read(const std::string path) {
    BinaryFileReader reader(path);
    timeStamps.reserve(1024);
    zippedChunks.reserve(1024);

    for (int i = 0; i < 1024; ++i) {
        reader.seek(4 + 4 * i, beg);

        unsigned short offset;
        reader.read<unsigned short>(offset);

        if (offset != 0) {
            reader.seek(4100 + 4 * i, beg);

            int timeStamp;
            reader.read<int>(timeStamp);
            timeStamps.push_back(timeStamp);

            reader.seek(offset * 4096 + 4, beg);

            int length;
            reader.read<int>(length);

            reader.seek(1, cur);

            std::vector<unsigned char> chunkData;
            chunkData.resize(length);
            reader.readBytes(&chunkData[0], length);
            zippedChunks.push_back(chunkData);
        } else {
            // This chunk hasn't been generated yet.

            // Push zero to the timeStamp.
            timeStamps.push_back(0);

            // Create a vector, resize it to zero and push it to zippedChunks.
            std::vector<unsigned char> chunkData(0);
            zippedChunks.push_back(chunkData);
        }
    }
}

inline void RegionFile::write(std::string path, const int rX, const int rZ) {
    path = path.append("\\r.").append(std::to_string(rX)).append(".").append(std::to_string(rZ)).append(".7rg");

    write(path);
}

void RegionFile::write(const std::string path) {
    BinaryFileWriter writer(path);

    unsigned char ch = 55;
    writer.writeByte(&ch);

    ch = 114;
    writer.writeByte(&ch);

    ch = 103;
    writer.writeByte(&ch);

    writer.seek(4100, std::ios_base::beg);

    for (int i = 0; i < 1024; ++i) {
        writer.writeInt32(&timeStamps[i]);
    }

    std::vector<short> offsets;
    offsets.reserve(1024);
    std::vector<unsigned char> size;
    size.reserve(1024);

    for (int j = 0; j < 1024; ++j) {
        if (zippedChunks[j].size() != 0) {
#pragma warning(suppress: 4244)
            int position = writer.baseStream.tellp();

            int pA = ((position - 4) / 4096) + 1;
            offsets.push_back(((position - 4) / 4096) + 1);
            writer.baseStream.seekp((offsets[j] * 4096) + 4, std::ios_base::beg);

#pragma warning(suppress: 4267)
            int chunkSize = zippedChunks[j].size();

            int BB = (chunkSize / 4096) + 1;
            size.push_back((chunkSize / 4096) + 1);

            writer.writeInt32(&chunkSize);
            ch = 0;
            writer.writeByte(&ch);
            writer.writeBytes(&zippedChunks[j][0], chunkSize);

            writer.seek((offsets[j] + size[j]) * 4096, std::ios_base::beg);
        } else {
            offsets.push_back(0);
            size.push_back(0);
        }
    }

    writer.seek(4, std::ios_base::beg);

    for (int k = 0; k < 1024; ++k) {
        writer.writeInt16(&offsets[k]);
        writer.writeByte(&ch);
        writer.writeByte(&size[k]);
    }
}
