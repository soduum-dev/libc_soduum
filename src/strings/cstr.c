#include <stdlib.h>
#include <string.h>
// fields of type cstr
struct soduum_cstr {

	char *heap;
	char stack[128];
	unsigned long len; // quanity of array
	unsigned long logicLen; // quanity of symvols

}; // work




// create cstr from char array
struct soduum_cstr soduum_charArray_cstrCreate(char *cstr) {
	struct soduum_cstr res; 
	res.logicLen = soduum_charArray_getLenght(cstr);
	if (res.logicLen < 128) 
	{
		res.heap = NULL;
		strcpy(res.stack, cstr); 
		res.len = 128; 
	}
	else {
		res.len = res.logicLen * 2 + 1;
		res.heap = malloc(res.len);
				// malloc check !!! !!! !!!
		strcpy(res.heap, cstr);
	}
	return res; 
	
} //work

// create cstr from cstr
struct soduum_cstr soduum_cstr_create(struct soduum_cstr *from) {
	if (from->heap != NULL) { 
		return soduum_charArray_cstrCreate(from->heap); }
	else {
		return soduum_charArray_cstrCreate(from->stack); }
} //work



// destroy cstr
void soduum_cstr_destroy(struct soduum_cstr *self) {
	if (self->heap != NULL) { 
		free(self->heap); self->heap = NULL;
	}
} //work

bool soduum_cstr_equals(struct soduum_cstr *f, struct soduum_cstr *s) {
	char *f_ptr, *s_ptr;
	if (f->heap == NULL) { f_ptr = f->stack; } else {f_ptr = f->heap; }
	if (s->heap == NULL) { s_ptr = s->stack; } else {s_ptr = s->heap; }
	return soduum_charArray_equals(f_ptr, s_ptr);
} //work





































