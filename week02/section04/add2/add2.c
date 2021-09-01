#include <stdio.h>
#include <stdlib.h>

int add2_s(int a, int b);

int main(int argc, char **argv) {
	int a = atoi(argv[1]);
	int b = atoi(argv[2]);
	printf("Asm: %d", add2_s(a,b));
	return 0;
}
