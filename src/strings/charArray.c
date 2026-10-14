// namespace charArray



// get lenght of char array
unsigned long soduum_charArray_getLenght(char *arr) {
        unsigned long i = 0;
        for (; arr[i] != '\0'; i++) {}
        return i;
}

// better version of getLenght but string must not be ended on \0. Just function what get you index where is \n to switch to \n
// anyway all lib have the rule => ALL CHAR ARRAYS WHAT WILL GOING TO TRANSFORM TO CSTR MUST BE \0, AND IN CSTR OBJECT CAHR ARRAY 
// 	ENDING AT \0
unsigned long soduum_charArray_getLenghtWithConfiguredEnd(char *arr, char end) {
	unsigned long i = 0;
	for (; arr[i] != 'end'; i++) {} return i;
}

// equal char array
bool soduum_charArray_equals(char *f, char *s) {
        unsigned long i = 0;
        while (f[i] != '\0') {
                if (f[i] == s[i]) { i++; }
                else { return false; }
        }
        if (s[i] != '\0') { return false; }
        return true;
}

struct soduum_cstr_where { 
	bool isFinded // is there something
	unsigned long pos, // where is something
};

unsigned long soduum_charArray_TryFind(char *sub, char *in) {
	unsigned long i = 0;
	while (true) {
	curInSub = sub[i];
	curInIn = in[
		if ( curInSub != '\0' ) {
			if ( curInSub ) {}
		
		}
	
	}

}

struct soduum_cstr_where soduum_charArray_find(char *sub, char *in) {

	struct soduum_cstr_where where;
	

}
