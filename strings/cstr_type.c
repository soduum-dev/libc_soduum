struct soduum_cstr {

	char *heap;
	char stack[128];
	unsigned long len; // quanity of array
	unsigned long logicLen; // quanity of symvols

};

unsigned long soduum_getLenght(char *arr) {
	unsigned long i = 0;
	for (; arr[i] != '\0'; i++) {} 
	return i;  
}

struct soduum_cstr soduum_cstr_create(char *cstr) {
	struct soduum_cstr res; 
	res.logicLen = soduum_getLenght(cstr);
	if (res.logicLen < 128) 
	{
		res.heap = NULL;
		strcpy(res.stack, cstr); 
		res.len = 128; 
	}
	else {
		res.len = res.logicLen * 2 + 1;
		res.heap = malloc(res.len);
		//malloc check
		strcpy(res.heap, cstr);
	}
	return res;
	
}

void soduum_cstr_destroy(struct soduum_cstr *self) {
	if (self->heap != NULL) { 
		free(self->heap); self->heap = NULL;
	}
}
