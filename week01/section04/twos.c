#include <stdio.h>
#include <stdint.h>

int main(int argc, char **argv) {
	int32_t signed_int = -6;

	uint32_t unsigned_int = 6;
	unsigned_int = ~unsigned_int;
	unsigned_int += 1;

	printf("%s\n", (uint32_t) signed_int == unsigned_int ? "same" : "not");	
}
