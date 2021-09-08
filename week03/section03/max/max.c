#include <stdio.h>
#include <stdlib.h>

int max_c(int, int);
int max_s(int, int);

int main(int argc, char **argv) {
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

    int c_result = max_c(a, b);
    printf("C: %d\n", c_result);

    int s_result = max_s(a, b);
    printf("Asm: %d\n", s_result);

    return 0;
}
