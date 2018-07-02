#pragma once

#include <string>

class Utils {
public:
    Utils();
    ~Utils();

    static int getMonoHash(std::string str);
};
