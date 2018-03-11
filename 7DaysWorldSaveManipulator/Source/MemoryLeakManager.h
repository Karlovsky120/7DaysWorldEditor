#pragma once
#include <set>

class MemoryLeakManager {
private:
	static std::set<void*> memoryAllocations;
	MemoryLeakManager();
	~MemoryLeakManager();

public:
	static void *MLMmalloc(size_t len);
	static void *MLMcalloc(size_t count, size_t size);
	static void MLMfree(void *block);
	static void freeMemoryLeaks();
};
