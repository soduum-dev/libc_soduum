#include "../include.h"
#include "libc_soduum_allocators.h"

bool soduum_mallocCheck(void *ptr) {
	if (ptr == NULL) { fprintf(stderr, "OS didnt allocate memory!"); return false;} 
	return true;
}

void *ptr soduum_mem_hardMalloc(unsigned long size) {

	void *ptr = malloc(size);
	if (soduum_mallocCheck(ptr)) {
		return ptr;
	}
	exit(1);

}


