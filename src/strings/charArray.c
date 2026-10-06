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
struct soduum_where { unsigned long i; bool is_there; }; 
/* 
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
*/ 
 
struct soduum_where soduum_charArray_findSubArray(char *arr, char *subArr) { 
 
        struct soduum_where = {0, true}; 
 
} 
 

