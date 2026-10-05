#include <stdlib.h>
#include <string.h>
// fields of type cstr
struct soduum_cstr {

	char *heap;
	char stack[128];
	unsigned long len; // quanity of array
	unsigned long logicLen; // quanity of symvols

}; // work

// get lenght of char array
unsigned long soduum_charArray_getLenght(char *arr) {
	unsigned long i = 0;
	for (; arr[i] != '\0'; i++) {} 
	return i;  
} // work

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

// equal char array bytes
bool soduum_charArray_equals(char *f, char *s) {
	unsigned long i = 0;
	while (f[i] != '\0') {
		if (f[i] == s[i]) { i++; }
		else { return false; }
	}
	if (s[i] != '\0') { return false; } 
	return true;
} //work

bool soduum_cstr_equals(struct soduum_cstr *f, struct soduum_cstr *s) {
	char *f_ptr, *s_ptr;
	if (f->heap == NULL) { f_ptr = f->stack; } else {f_ptr = f->heap; }
	if (s->heap == NULL) { s_ptr = s->stack; } else {s_ptr = s->heap; }
	return soduum_charArray_equals(f_ptr, s_ptr);
} //work



// soduum_charArrayBytesEquals that return where is false returned
struct soduum_where { unsigned long i; bool is_there; };
struct soduum_where soduum_charArrayBytesEquals(char *f, char *s) {
	unsigned long i = 0;
	struct soduum_where res = {0, false}
	while (f[i] != '\0') {
		if (f[i] == s[i]) { i++; }
		else { 
		       	res.i = i;
			return res; }
	}
	if (s[i] != '\0') { 
		res.i = i;
		return res; }
       	res.is_there = true;
	res.i = i;	
	return res;
} //idk



































