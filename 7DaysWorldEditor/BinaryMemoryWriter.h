#pragma once

#include <vector>

class BinaryMemoryWriter {
private:
	std::vector<unsigned char> unzippedData;

public:
	unsigned int position = 0;

	template <typename T>
	inline void write(const T &data) {
		memcpy(&unzippedData[position], &data, sizeof(T));
		position += sizeof(T);
	}

	template <typename T>
	inline void writeConst(const T data) {
		memcpy(&unzippedData[position], &data, sizeof(T));
		position += sizeof(T);
	}

	template<>
	inline void write(const std::string &data) {
	#pragma warning(suppress: 4267)
		unsigned char length = data.size();
		write<unsigned char>(length);

		if (length != 0) {
			writeBytes(data, length);
		}
	}

	template<>
	inline void writeConst(const std::string data) {
	#pragma warning(suppress: 4267)
		unsigned char length = data.size();
		write<unsigned char>(length);

		if (length != 0) {
			writeBytes(data, length);
		}
	}

	template <typename T>
	inline void writeBytes(const T &data, int count) {
		memcpy(&unzippedData[position], &data, count);
		position += count;
	}

	template<typename T, typename C>
	inline void writeMultipleSimple(const std::vector<T> &listOfTs) {
	#pragma warning(suppress: 4267)
		C count = listOfTs.size();
		write<C>(count);
		writeMultipleSimple(listOfTs, count);
	}

	template<typename T, typename C>
	inline void writeMultipleSimple(const std::vector<T> &listOfTs, C &count) {
		for (C i = 0; i < count; ++i) {
			write<T>(listOfTs[i]);
		}
	}

	template<typename T, typename C>
	inline void writeMultipleComplex(const std::vector<T> &listOfTs) {
	#pragma warning(suppress: 4267)
		C count = listOfTs.size();
		write<C>(count);
		writeMultipleComplex(listOfTs, count);
	}

	template<typename T, typename C>
	inline void writeMultipleComplex(const std::vector<T> &listOfTs, C &count) {
		for (C i = 0; i < count; ++i) {
			listOfTs[i].write(*this);
		}
	}

	void fetchZipped(std::vector<unsigned char> &zipped);
	void fetchUnzipped(std::vector<unsigned char> &unzipped);

	BinaryMemoryWriter(int reservedBytes);
	~BinaryMemoryWriter();
};

