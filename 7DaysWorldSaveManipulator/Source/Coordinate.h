#pragma once
#include "DllHeader.h"

template <class T>
class SDWSM_API Coordinate {
public:
	T x;
	T y;
	T z;

	inline bool operator<(const Coordinate& rhs) const {
		if (this->x < rhs.x) {
			return true;
		}
		else if (this->x == rhs.x) {
			if (this->z < rhs.z) {
				return true;
			}
			else if (this->z == rhs.z) {
				if (this->y < rhs.y) {
					return true;
				}
			}
		}

		return false;
	}
};
