#include "MemoryLeakManager.h"

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
	for each (void *leak in memoryAllocations) {
		free(leak);
	}

	memoryAllocations.clear();
}

MemoryLeakManager::MemoryLeakManager() {};
MemoryLeakManager::~MemoryLeakManager() {};