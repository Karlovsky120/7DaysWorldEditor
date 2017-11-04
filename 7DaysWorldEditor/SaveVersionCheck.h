#pragma once

#include "CurrentVersionConfigConstants.h"

#include <string>

class SaveVersionCheck {
public:
	static int checkVersion(int readVersion, std::string objectName);

	SaveVersionCheck();
	~SaveVersionCheck();
};