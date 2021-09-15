#include <stdio.h>
#include <stdlib.h>

int fact_c(int);
int fact_s(int);

int main(int argc, char **argv) {
    int num = atoi(argv[1]);

    int c_result = fact_c(num);
    printf("C: %d\n", c_result);

    int s_result = fact_s(num);
    printf("Asm: %d\n", s_result);

    return 0;
}
