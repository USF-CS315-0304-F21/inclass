#include <stdio.h>

void ldr_shift_s(int *, int);

#define ARR_LEN 3

int main(int argc, char **argv) {
    int arr[ARR_LEN] = {1, 2, 4};
    
    ldr_shift_s(arr, ARR_LEN);
    
    for (int i = 0; i < ARR_LEN; i++) {
        printf("arr[%d]: %d\n", i, arr[i]);
    }
    return 0;
}
