#include <stdio.h>

int strlen_c(char*);
int strlen_s(char*);

int main(int argc, char **argv) {
    char *str = argv[1];

    int c_result = strlen_c(str);
    printf("C: %d\n", c_result);

    int s_result = strlen_s(str);
    printf("Asm: %d\n", s_result);

    return 0;
}
