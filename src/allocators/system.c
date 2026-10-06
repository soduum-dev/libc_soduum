bool soduum_mallocCheck(void *ptr) {
	if (ptr == NULL) { return false; fprintf(stderr, "OS didnt allocate memory!"); }
	return true;
}


