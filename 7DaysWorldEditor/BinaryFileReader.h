#pragma once
#include <string>
#include <fstream>

#include "wx\log.h"

class BinaryFileReader {
private:
	std::ifstream baseStream;

public:
	template <typename T>
	inline void read(T &data) {
		baseStream.read((char *)&data, sizeof(T));
	}

	template <>
	inline void read(std::string &data) {
		char length;
		baseStream.read(&length, 1);

		unsigned char *characters = new unsigned char[length];
		baseStream.read((char*)characters, length);

		data = std::string((char*)characters, length);
		delete[] characters;
	}

	inline void readBytes(unsigned char data[], int count) {
		baseStream.read((char*)data, count);
	}

	inline void seek(int amount, std::ios_base::seekdir seekStart) {
		baseStream.seekg(amount, seekStart);
	}

	BinaryFileReader(std::string const path) {
		baseStream.open(path, std::ios::binary | std::ios::in);

		if (!baseStream.good()) {
			std::string errorMsg = "Failed to open file at " + path;
			wxLogError(errorMsg.c_str());

			throw std::ios_base::failure(errorMsg);
		}
	}

	~BinaryFileReader() {
		baseStream.close();
	}

	BinaryFileReader(const BinaryFileReader&) = delete;
	BinaryFileReader& operator=(const BinaryFileReader&) = delete;
};
