/*
	$ ./echo_upper something [-u]
	something
	$ ./echo_upper something -u
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
			if (i != 0) {
				str = argv[i];
			}
		}
	}
	
	if (upper && str) {
		for (int j = 0; j < strlen(str); j++) {
			if (str[j] >= 'a' && str[j] <= 'z') {
				str[j] += 'A' - 'a';
			}
		}
	}
	printf("%s\n", str ? str : "poorly formatted");
	return 0;
}
