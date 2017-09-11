#include "SleeperVolume.h"

#include "BinaryMemoryReader.h"
#include "SpawnPoint.h"

void SleeperVolume::read(BinaryMemoryReader &reader) {
	reader.read<unsigned char>(sleeperVolumeVersion);
	reader.read<std::string>(qj);

	reader.read<int>(mins.x);
	reader.read<int>(mins.y);
	reader.read<int>(mins.z);

	reader.read<int>(maxs.x);
	reader.read<int>(maxs.y);
	reader.read<int>(maxs.z);

	reader.read<unsigned _int64>(bj);
	reader.read<int>(pj);

	reader.read<int>(tj);
	reader.read<int>(uj);

	reader.read<std::string>(ij);

	reader.read<int>(xj);
	reader.read<bool>(yj);
	reader.read<bool>(lj);

	reader.readMultipleComplex<SpawnPoint, unsigned char>(dj);

	unsigned char fjCount;
	reader.read<unsigned char>(fjCount);

	if (fjCount > 0) {
		reader.readMultipleSimple<unsigned char, unsigned char>(fj, fjCount);
	}

	unsigned char ajCount;
	reader.read<unsigned char>(ajCount);

	if (ajCount > 0) {
		reader.readMultipleSimple<int, unsigned char>(aj, ajCount);
	}

	unsigned char jjCount;
	reader.read<unsigned char>(jjCount);

	if (jjCount > 0) {
		int first;
		reader.read<int>(first);
		std::string second;
		reader.read<std::string>(second);
		(jj)[first] = second;
	}

	unsigned char rjCount;
	reader.read<unsigned char>(rjCount);

	if (rjCount > 0) {
		reader.readMultipleSimple<int, unsigned char>(rj, ajCount);
	}
}

SleeperVolume::SleeperVolume() {}
SleeperVolume::~SleeperVolume() {}