// namespace charArray



// get lenght of char array
unsigned long soduum_charArray_getLenght(char *arr) {
        unsigned long i = 0;
        for (; arr[i] != '\0'; i++) {}
        return i;
} // work



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




// soduum_charArray_bytesEquals that return where is false returned 
struct soduum_where { unsigned long i; bool isThere; }; 
 
struct soduum_where soduum_charArray_BytesEqualAndStop(char *arr, char *sub) {

	struct soduum_where stop = {0, true};
	
	for (unsigned long i = 0; arr[stop.i] == sub[i]; stop.i++) { i++; }
	// warning lenght of 
}


struct soduum_where soduum_charArray_findSubArray(char *arr, char *subArr) { 
 
        struct soduum_where where = {0, true};

	for (unsigned long i = 0; subArr[i] != '\0'; i++) {

		if (arr[where.i] == subArr[i]) { where.i++; where.isThere = true; }
		else { where.isThere = false; }

		
	}	

} 
 

