#pragma once
#include <string>
#include <fstream>

class BinaryFileReader {
public:
	std::ifstream baseStream;

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

	inline bool open(std::string const& path) {
		baseStream.open(path, std::ios::binary | std::ios::in);

		return baseStream.good();
	}

	BinaryFileReader() {}

	~BinaryFileReader() {
		baseStream.close();
	}

	BinaryFileReader(const BinaryFileReader&) = delete;
	BinaryFileReader& operator=(const BinaryFileReader&) = delete;
};