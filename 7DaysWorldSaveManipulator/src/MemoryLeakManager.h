#pragma once

#include <set>

class MemoryLeakManager {
public:
    static void *MLMmalloc(size_t len);
    static void *MLMcalloc(size_t count, size_t size);
    static void MLMfree(void *block);
    static void freeMemoryLeaks();

private:
    static std::set<void*> memoryAllocations;

    MemoryLeakManager();
    ~MemoryLeakManager();
};
