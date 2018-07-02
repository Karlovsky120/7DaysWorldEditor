#include "MemoryLeakManager.h"

#include <algorithm>

std::set<void*> MemoryLeakManager::memoryAllocations;

void *MemoryLeakManager::MLMmalloc(size_t len) {
	void *block = malloc(len);
	memoryAllocations.insert(block);

	return block;
}

void *MemoryLeakManager::MLMcalloc(size_t count, size_t size) {
	void *block = calloc(count, size);
	memoryAllocations.insert(block);

	return block;
}

void MemoryLeakManager::MLMfree(void *block) {
	free(block);
	memoryAllocations.erase(block);
}

void MemoryLeakManager::freeMemoryLeaks() {
	for_each(memoryAllocations.begin(), memoryAllocations.end(), free);

	memoryAllocations.clear();
}

MemoryLeakManager::MemoryLeakManager() {};
MemoryLeakManager::~MemoryLeakManager() {};
