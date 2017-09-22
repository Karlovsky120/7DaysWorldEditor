#pragma once
#include "Unzip.h"

#include <vector>

class BinaryMemoryReader {
private:
	HZIP hz;

	long length = 0;

public:
	unsigned int position = 0;

	template <typename T>
	inline void read(T &data) {
		UnzipItem(hz, 0, &data, sizeof(T));
		position += sizeof(T);
	}

	template <>
	inline void read(std::string &data) {
		unsigned char length;
		read(length);
		//UnzipItem(hz, 0, &length, 1);
		//++position;
		
		if (length != 0) {
			unsigned char *stringData = new unsigned char[length];
			UnzipItem(hz, 0, stringData, length);

			data = std::string((const char *)stringData, (size_t)length);
			delete stringData;
			position += length;
		} else {
			data = std::string();
		}
	}


	inline void readBytes(unsigned char *data, int count) {
		UnzipItem(hz, 0, data, count);
		position += count;
	}

	inline void readBytes(std::vector<unsigned char> data, int count) {
		data.resize(count);
		UnzipItem(hz, 0, data.data(), count);
		position += count;
	}


	template<typename T, typename C>
	inline void readMultipleSimple(std::vector<T> &listOfTs) {
		C counter;
		read<C>(counter);
		readMultipleSimple(listOfTs, counter);
	}

	template<typename T, typename C>
	inline void readMultipleSimple(std::vector<T> &listOfTs, C &count) {
		for (C i = 0; i < count; ++i) {
			T item;
			read(item);
			listOfTs.push_back(item);
		}
	}

	template<typename T, typename C>
	inline void readMultipleComplex(std::vector<T> &listOfTs) {
		C counter;
		read<C>(counter);
		readMultipleComplex(listOfTs, counter);
	}

	template<typename T, typename C>
	inline void readMultipleComplex(std::vector<T> &listOfTs, C &count) {
		for (C i = 0; i < count; ++i) {
			T item;
			item.read(*this);
			listOfTs.push_back(item);
		}
	}

	bool initialize(std::vector<unsigned char> &zipped);

	bool isValidRead() {
		return position != length;
	}

	BinaryMemoryReader();
	~BinaryMemoryReader();
};