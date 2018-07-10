#pragma once

#include <fstream>
#include <string>

struct SeekPoint {
    enum SeekPointEnum {
        beg = std::ios_base::beg,
        cur = std::ios_base::cur,
        end = std::ios_base::end
    };
};

class BinaryFileReader {
public:
    BinaryFileReader(std::string const path) {
        baseStream.open(path, std::ios::binary | std::ios::in);

        if (!baseStream.good()) {
            throw std::ios_base::failure("Failed to open file at " + path);
        }
    }

    ~BinaryFileReader() {
        baseStream.close();
    }

    BinaryFileReader(const BinaryFileReader&) = delete;
    BinaryFileReader& operator=(const BinaryFileReader&) = delete;

    unsigned int getPosition() {
        return (unsigned int)baseStream.tellg();
    }

    template <typename T>
    inline void read(T &data) {
        baseStream.read((char *)&data, sizeof(T));

#ifdef DEBUG
        position = baseStream.tellg();
#endif
    }

    template <>
    void read(std::string &data) = delete;

    template <typename T>
    void readString(std::string &data, bool alignTo4Bytes = false) {
        T length;
        read<T>(length);

        unsigned char *characters = new unsigned char[length];
        baseStream.read((char *)characters, length);

        data = std::string((char *)characters, length);
        delete[] characters;

        if (alignTo4Bytes) {
            seekToAlignTo4Bytes();
        }

#ifdef DEBUG
        position = baseStream.tellg();
#endif
    }

    /*template <>
    void read(std::string &data) {
        char length;
        baseStream.read(&length, 1);

        unsigned char *characters = new unsigned char[length];
        baseStream.read((char *)characters, length);

        data = std::string((char *)characters, length);
        delete[] characters;
    }

    void readStringAlternate(std::string &data) {
        int length;
        read<int>(length);

        char cString[255];

        for (int i = 0; i < length; ++i) {
            read<char>(cString[i]);
        }

        data = std::string(cString);
    }*/

    void readCString(std::string &data) {
        char cString[255];
        char current;
        int offset = -1;

        do {
            baseStream.read(&current, 1);
            cString[++offset] = current;
        } while (current != '\0' && offset < 256);

        data = std::string(cString);

#ifdef DEBUG
        position = baseStream.tellg();
#endif
    }

    inline void readBigEndian(unsigned int &data) {
        baseStream.read((char *)&data, sizeof(unsigned int));
        data = _byteswap_ulong(data);

#ifdef DEBUG
        position = baseStream.tellg();
#endif
    }

    inline void readBytes(unsigned char data[], unsigned int count) {
        baseStream.read((char *)data, count);

#ifdef DEBUG
        position = baseStream.tellg();
#endif
    }

    inline void readBytes(std::vector<unsigned char> data, unsigned int count) {
        data.resize(count);
        baseStream.read((char*)&data[0], count);

#ifdef DEBUG
        position = baseStream.tellg();
#endif
    }

    inline void seek(int amount, SeekPoint::SeekPointEnum seekStart = SeekPoint::cur) {
        baseStream.seekg(amount, seekStart);

#ifdef DEBUG
        position = baseStream.tellg();
#endif
    }

    inline void seekToAlignTo4Bytes() {
        seek((4 - (getPosition() % 4)) % 4);

#ifdef DEBUG
        position = baseStream.tellg();
#endif
    }

    template <typename L, typename S>
    void seekOverArray(bool alignTo4Bytes = false) {
        L length;
        read<L>(length);

        seek(length * sizeof(S));

        if (alignTo4Bytes) {
            seekToAlignTo4Bytes();
        }

#ifdef DEBUG
        position = baseStream.tellg();
#endif
    }

private:
    std::ifstream baseStream;
#ifdef DEBUG
    std::streampos position;
#endif
};
