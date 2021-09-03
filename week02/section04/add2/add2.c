#include <stdio.h>
#include <stdlib.h>

int add2_s(int a, int b);
int add2_c(int a, int b);
void foobar();

int main(int argc, char **argv) {
	int a = atoi(argv[1]);
	int b = atoi(argv[2]);

	int c_result = add2_c(a, b);
	int s_result = add2_s(a, b);
	printf("C: %d\nAsm: %d\n", c_result, s_result);

	foobar();
	
	return 0;
}
