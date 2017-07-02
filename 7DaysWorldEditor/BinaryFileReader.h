#pragma once

#include <string>
#include <fstream>

class BinaryFileReader {

public:
	std::ifstream baseStream;

	inline void readBoolean(bool *data) {
		baseStream.read((char*)data, 1);
	}

	inline void readByte(unsigned char *data) {
		baseStream.read((char*)data, 1);
	}

	inline void readBytes(unsigned char data[], int count) {
		baseStream.read((char*)data, count);
	}

	inline void readDouble(double * data) {
		baseStream.read((char*)data, 8);
	}

	inline void readInt16(short *data) {
		baseStream.read((char*)data, 2);
	}

	inline void readInt32(int *data) {
		baseStream.read((char*)data, 4);
	}

	inline void readInt64(_int64 *data) {
		baseStream.read((char*)data, 8);
	}

	inline void readSByte(char * data) {
		baseStream.read(data, 1);
	}

	inline void readSingle(float * data) {
		baseStream.read((char*)data, 4);
	}

	inline void readString(std::string *data) {
		char length;
		baseStream.read(&length, 1);

		unsigned char *characters = new unsigned char[length];
		baseStream.read((char*)characters, length);

		*data = std::string((char*)characters, length);
	}

	inline void readUInt16(unsigned short *data) {
		baseStream.read((char*)data, 2);
	}

	inline void readUInt32(unsigned int *data) {
		baseStream.read((char*)data, 4);
	}

	inline void readUInt64(unsigned _int64 *data) {
		baseStream.read((char*)data, 8);
	}

	inline void seek(int amount, std::ios_base::seekdir seekStart) {
		baseStream.seekg(amount, seekStart);
	}

	BinaryFileReader(std::string const& path) {
		baseStream.open(path, std::ios::binary | std::ios::in);
	}

	~BinaryFileReader() {
		baseStream.close();
	}

	BinaryFileReader(const BinaryFileReader&) = delete;
	BinaryFileReader& operator=(const BinaryFileReader&) = delete;
};


/*
//std::vector<unsigned char> stream;
long position = 0;

inline void readBoolean(bool *data) {

	*data = stream[position] > 0;

	//data = reinterpret_cast<bool*>(&stream[position]);
	++position;

	//baseStream.read((char*)data, 1);*/