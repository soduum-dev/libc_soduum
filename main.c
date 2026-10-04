#include "all.h"
#include <stdio.h>
int convert(bool o) {

	if (o == false) { return 0; }
	else { return 1; }	

}

int main(int argc, char* argv[]) {

	printf("%d", convert(cstr_find(argv[1], argv[2]).is_finded));

}
