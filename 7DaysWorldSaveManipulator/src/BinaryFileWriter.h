#pragma once

#include <string>
#include <fstream>

class BinaryFileWriter {
public:
	std::ofstream baseStream;

	inline void writeBoolean(bool *data) {
		baseStream.write((char*)data, 1);
	}

	inline void writeByte(unsigned char *data) {
		baseStream.write((char*)data, 1);
	}

	inline void writeBytes(unsigned char data[], int count) {
		baseStream.write((char*)data, count);
	}

	inline void writeDouble(double * data) {
		baseStream.write((char*)data, 8);
	}

	inline void writeInt16(short *data) {
		baseStream.write((char*)data, 2);
	}

	inline void writeInt32(int *data) {
		baseStream.write((char*)data, 4);
	}

	inline void writeInt64(_int64 *data) {
		baseStream.write((char*)data, 8);
	}

	inline void writeSByte(char * data) {
		baseStream.write(data, 1);
	}

	inline void writeSingle(float * data) {
		baseStream.write((char*)data, 4);
	}

	inline void  writeUInt16(unsigned short *data) {
		baseStream.write((char*)data, 2);
	}

	inline void writeUInt32(unsigned int *data) {
		baseStream.write((char*)data, 4);
	}

	inline void writeUInt68(unsigned _int64 *data) {
		baseStream.write((char*)data, 8);
	}

	inline void seek(int amount, std::ios_base::seekdir seekStart) {
#pragma warning(suppress: 4244)
		int currentPosition = baseStream.tellp();

		// Get the start and the end of the file to get the size.
		baseStream.seekp(0, std::ios_base::beg);
#pragma warning(suppress: 4244)
		int start = baseStream.tellp();
		baseStream.seekp(0, std::ios_base::end);
#pragma warning(suppress: 4244)
		int end = baseStream.tellp();
		baseStream.seekp(currentPosition, std::ios_base::beg);

		int size = end - start;

		int additionalOffset;

		switch (seekStart) {
		case (std::ios_base::beg):
			additionalOffset = amount - size;
			break;
		case (std::ios_base::cur):
			additionalOffset = amount - size + currentPosition;
			break;
		case std::ios_base::end:
			additionalOffset = amount;
			break;
		}

		if (0 < additionalOffset) {
			baseStream.seekp(0, std::ios_base::end);

			unsigned char ch = 0;
			for (int i = 0; i < additionalOffset; ++i) {
				baseStream.write((char*)&ch, 1);
			}
		}
		else {
			baseStream.seekp(amount, seekStart);
		}
	}

	BinaryFileWriter(std::string const& path) {
		baseStream.open(path, std::ios::binary | std::ios::out);

		if (!baseStream.good()) {
			throw std::ios_base::failure("Failed to write to file at " + path);
		}
	}

	~BinaryFileWriter() {
		baseStream.close();
	}

	BinaryFileWriter(const BinaryFileWriter&) = delete;
	BinaryFileWriter& operator=(const BinaryFileWriter&) = delete;
};
