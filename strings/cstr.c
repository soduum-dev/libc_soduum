	bool cstr_bytes_equals(char *f, char *s) {
	
		unsigned long i = 0;

		for (; f[i] != '\0'; i++) {
			if (f[i] == s[i]) {} else { return false; }
		}

		if (s[i] != '\0') { return false; }

		return true;

	} //work


	struct where { unsigned long index; bool is_finded; };

	struct where cstr_find_substr(char *str, char *sub) { struct where res = { 0, true };
		
		unsigned long i = 0;
		while (str[res.index] != '\0') {
			// нужно найти длинну подстроки чтобы понять когда оназаканчивается
			if (str[res.index] == sub[i]) { res.index++; i++;  } else { i = 0; }
		
		}
		return 
	
	}





struct cstr_finded {
	unsigned long index; // index of subcstr
	bool is_finded; // is subcstr finded?
};

	struct cstr_finded cstr_find(char *cstr, char sub_cstr) {
		struct cstr_finded result = {0, true};
		
		for (unsigned long i = 0; cstr[result.index] != '\0'; result.index++) {
			
			if (cstr[result.index] == sub_cstr[i]) { i++; result.is_finded = true; } else { result.index--; i = 0; result.is_finded = false; }	
		
		}
	
	}

