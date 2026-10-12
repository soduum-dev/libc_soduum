#include "../include.h"



// fields of type cstr
struct soduum_cstr {

	char *heap;
	char stack[128];
	unsigned long len; // quanity of array
	unsigned long logicLen; // quanity of symvols

};


// alloc memory, size: "logicLen", and copy char array to this memory
struct soduum_cstr soduum_charArray_MakeCstr(char *cstr, unsigned long logicLen) {

	struct soduum_cstr res;
	res.logicLen = logicLen;
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
		// there is a trash in res.stack !!!
		strcpy(res.heap, cstr);
	}
	return res; 

}

// use MakeCstr to create cstr object from char array
struct soduum_cstr soduum_charArray_cstrCreate(char *from) {
	struct soduum_cstr cstr = soduum_charArray_MakeCstr(from, soduum_charArray_getLenght(from));
	return cstr;
	
}

// create cstr from cstr
struct soduum_cstr soduum_cstr_create(struct soduum_cstr *from) {
	if (from->heap != NULL) { 
		return soduum_charArray_cstrCreate(from->heap); }
	else {
		return soduum_charArray_cstrCreate(from->stack); }
} // this is work but slow bcse of sec check in cstrCreate about "is it heap or stack?" "too long or not?"

// i think, it is better
// i switch name and delete old fn after test new, fast function
struct soduum_cstr soduum_cstr_createFast(struct soduum_cstr *from) {

	if (from->heap == NULL) { return soduum_charArray_MakeCstr(from->stack, from->logicLen); }
	return soduum_charArray_MakeCstr(from->heap, from->logicLen);

}


// destroy cstr
bool soduum_cstr_destroy(struct soduum_cstr *self) {
	if (self->heap != NULL) { // and if this null but stack is logicaly empty "way way way way wa..."
		free(self->heap);// self->heap = NULL; // you could ask: "why not? ", because i dont know will i shift 
		return true;		  // responicibilty for destroy on non-where-object-was-created functions, if i will, it will be okay, i will free self->heap and anyone won't double free memory. But anyway if someone do it again i think it means i get an logic error what wont crash my programm. Choice is free double but program wont crush and you dont need to know where string must be destroy(you dont know when object is alive), or double free(you will know about alive or not(maybe), after segfault, and you could fix it easer). If i wont, there wont be need for this.  
	} else { return false; }
// and also should i return void or bool(to know was ptr null or not)? i think it would be good
}


// bcause of this, you get second destroyer
bool soduum_cstr_destroyToNull(struct soduum_cstr *self) {
	if (soduum_cstr_destroy(self)) {
		self->heap = NULL;
		return true;
	} 
	
	return false;
}

bool soduum_cstr_equals(struct soduum_cstr *f, struct soduum_cstr *s) {
	char *f_ptr, *s_ptr;
	if (f->heap == NULL) { f_ptr = f->stack; } else {f_ptr = f->heap; }
	if (s->heap == NULL) { s_ptr = s->stack; } else {s_ptr = s->heap; }
	return soduum_charArray_equals(f_ptr, s_ptr);
}





































