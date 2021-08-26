/*
	./echo_upper something
	something

	./echo_upper something -u
	SOMETHING
*/

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
	bool upper = false;
	char *str = NULL;
	
	for (int i = 0; i < argc; i++) {
		if (!strncmp(argv[i], "-u", 2)) {
			upper = true;
		} else {
			str = argv[i];
		}
	}

	if (upper) {
		for (unsigned int j = 0; j < strlen(str); j++) {
			if (str[j] >= 'a' && str[j] <= 'z') {
				str[j] -= 32;
			}
		}
	}

	printf("%s\n", str);

	return 0;
}
