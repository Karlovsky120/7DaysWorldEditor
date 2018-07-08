#pragma once

#include <fstream>
#include <string>

enum seekPoint {
    beg = std::ios_base::beg,
    cur = std::ios_base::cur,
    end = std::ios_base::end
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

    int getPosition() {
        return baseStream.tellg();
    }

    template <typename T>
    inline void read(T &data) {
        baseStream.read((char *)&data, sizeof(T));
    }

    template <>
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
        baseStream.read(&length, 4);

        char cString[255];

        for (i = 0; i < length; ++i) {
            baseStream.read(cString[i]);
        }

        data = std::string(cString);
    }

    void readCString(std::string &data) {
        char cString[25];
        char current;
        int offset = -1;

        do {
            baseStream.read(&current, 1);
            cString[++offset] = current;
        } while (current != '\0');

        data = std::string(cString);
    }

    inline void readBigEndian(unsigned int &data) {
        baseStream.read((char *)&data, sizeof(unsigned int));
        data = _byteswap_ulong(data);
    }

    inline void readBytes(unsigned char data[], int count) {
        baseStream.read((char *)data, count);
    }

    inline void seek(int amount, seekPoint seekStart) {
        baseStream.seekg(amount, seekStart);
    }

private:
    std::ifstream baseStream;
};
