#pragma once

#include <string>
#include <vector>

	class BinaryMemoryReader {

	public:
		std::vector<unsigned char> stream;
		int position = 0;

		template <typename T>
		inline void read(T **data) {
			*data = (T*)&stream[position];
			position += sizeof(T);
		}

		inline void read(std::string **data) {
			unsigned char length = stream[position];
			++position;

			*data = (std::string*)&stream[position];
			position += length;
		}

		inline void readBytes(unsigned char **data, int count) {
			*data = &stream[position];
			position += count;
		}

		inline void seek(int amount, int start) {
			switch (start) {
			case 0:
				position = amount;
				break;
			case 1:
				position += amount;
				break;
			}
		}

		template<typename T, typename C>
		inline void readMultipleSimple(std::vector<T *> listOfTs) {
			C *counter;
			read<C>(&counter);
			readMultipleSimple(listOfTs, counter);
		}

		template<typename T, typename C>
		inline void readMultipleSimple(std::vector<T *> listOfTs, C *counter) {
			for (C i = 0; i < *counter; ++i) {
				T *item;
				read(&item);
				listOfTs.push_back(item);
			}
		}

		template<typename T, typename C>
		inline void readMultipleComplex(std::vector<T *> listOfTs) {
			C *counter;
			read<C>(&counter);
			readMultipleComplex(listOfTs, counter);
		}

		template<typename T, typename C>
		inline void readMultipleComplex(std::vector<T *> listOfTs, C *counter) {
			for (C i = 0; i < *counter; ++i) {
				T *item = new T();
				listOfTs.push_back(item->read(this));
			}
		}




		/*
		inline void readString(std::string **data) {
		unsigned char length = stream[position];
		++position;

		*data = (std::string*)&stream[position];
		position += length;
		}

		inline void readBoolean(bool **data) {
			*data = (bool*)&stream[position];
			++position;
		}

		inline void readByte(unsigned char **data) {
			*data = &stream[position];
			++position;
		}



		inline void readDouble(double **data) {
			*data = (double*)&stream[position];
			//memcpy(data, &stream[position], sizeof(double));
			position += sizeof(double);
		}

		inline void readInt16(short **data) {
			*data = (short*)&stream[position];
			//memcpy(data, &stream[position], sizeof(short));
			position += sizeof(short);
		}

		inline void readInt32(int **data) {
			*data = (int*)&stream[position];
			//memcpy(data, &stream[position], sizeof(int));
			position += sizeof(int);
		}

		inline void readInt64(_int64 **data) {
			*data = (_int64*)&stream[position];
			//memcpy(data, &stream[position], sizeof(_int64));
			position += sizeof(_int64);
		}

		inline void readSByte(char **data) {
			*data = (char*)&stream[position];
			//*data = (char)stream[position];
			++position;
		}

		inline void readSingle(float **data) {
			*data = (float*)&stream[position];
			//memcpy(data, &stream[position], sizeof(float));
			position += sizeof(float);
		}



		inline void readUInt16(unsigned short **data) {
			*data = (unsigned short*)&stream[position];
			//memcpy(data, &stream[position], sizeof(unsigned short));
			position += sizeof(unsigned short);
		}

		inline void readUInt32(unsigned int **data) {
			*data = (unsigned int*)&stream[position];
			//memcpy(data, &stream[position], sizeof(unsigned int));
			position += sizeof(unsigned int);
		}

		inline void readUInt64(unsigned _int64 **data) {
			*data = (unsigned _int64*)&stream[position];
			//memcpy(data, &stream[position], sizeof(unsigned _int64));
			position += sizeof(unsigned _int64);
		}*/



		BinaryMemoryReader(std::vector<unsigned char> &stream) :
			stream(stream) {}

		~BinaryMemoryReader() {}

		BinaryMemoryReader(const BinaryMemoryReader&) = delete;
		BinaryMemoryReader& operator=(const BinaryMemoryReader&) = delete;
	};