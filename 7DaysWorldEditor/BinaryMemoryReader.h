#pragma once
#include "VersionCheck.h"
#include "Unzip.h"

#include <vector>

class BinaryMemoryReader : public VersionCheck {
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
	inline int readMultipleComplex(std::vector<T> &listOfTs, std::string objectName) {
		C counter;
		read<C>(counter);
		return readMultipleComplex(listOfTs, counter, objectName);
	}

	template<typename T, typename C>
	inline int readMultipleComplex(std::vector<T> &listOfTs, C &count, std::string objectName) {
		for (C i = 0; i < count; ++i) {
			T item;
			CHECK_VERSION(item.read(*this), objectName);
			listOfTs.push_back(item);
		}

		return 0;
	}

	bool initialize(std::vector<unsigned char> &zipped);

	int isValidRead() {
		return position == length;
	}

	BinaryMemoryReader();
	~BinaryMemoryReader();
};