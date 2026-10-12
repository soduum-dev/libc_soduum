#include "../include.h"
#include "libc_soduum_allocators.h"

struct soduum_arena {

	void *heap;
	bool alive = true; // for future
	unsigned long logicLen;
	unsigned long len;


};

struct soduum_arena soduum_arena_create(unsigned long size) {
	struct soduum_arena arena = {
		malloc(size), false,
		0, size 
	};

	arena.isAcive = soduum_mallocCheck(arena.heap);
	// this check is better if there is exit(1)
	return arena;
}

void soduum_arena_Copy(void *from, , unsigned long logicSize, void *to) {}

struct soduum_arena soduum_arena_copy(struct soduum_arena *from) {

	struct soduum_arena arena = {
		.heap = malloc(from->len), 
		.logicLen = from->logicLen,
		.len = from->len,
	};

	arena.alive = soduum_arena_mallocCheck(arena.heap);
	if (arena.isActive) {
	// copy all from from original arena 
	} 
	return arena;

}

void soduum_arena_destroy(struct soduum_arena *self) { 
	free(self->heap); // self->heap = NULL not help, if you use what was free u have an logic error you 100% will need to fix it 
}



void *ptr soduum_arena_malloc(struct soduum_allocator *self, unsigned long logicSize) {}

void soduum_arena_freeAll(struct soduum_allocator *self) {}










































