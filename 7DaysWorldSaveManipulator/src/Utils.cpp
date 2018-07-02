#include "Utils.h"

int Utils::getMonoHash(std::string str) {
	char* src = &str[0];
	char* chPtr2 = src; // + offset; // RuntimeHelpers.OffsetToStringData;
	char* chPtr3 = (chPtr2 + str.length()) - 1;
	int num = 0;
	while (chPtr2 < chPtr3) {
		num = ((num << 5) - num) + chPtr2[0];
		num = ((num << 5) - num) + chPtr2[1];
		chPtr2 += 2;
	}
	chPtr3++;
	if (chPtr2 < chPtr3) {
		num = ((num << 5) - num) + chPtr2[0];
	}
	return num;
}

Utils::Utils() {}
Utils::~Utils() {}