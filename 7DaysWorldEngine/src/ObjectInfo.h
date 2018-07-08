#pragma once

class ObjectInfo {
public:
    unsigned _int64 index;
    unsigned int offset;
    unsigned int size;
    unsigned int type;
    unsigned short inheritedUnityClass;
    unsigned short scriptIndex;
    unsigned char unknown;

    ObjectInfo();
    ~ObjectInfo();
};