#include <stdio.h>

int fmi_rec_c(int *arr, int *start, int *end, int *max);
int fmi_rec_s(int *arr, int *start, int *end, int *max);

int main(int argc, char **argv) {
    int arr[4] = {1, 2, 3, 4};

    int c_result = fmi_rec_c(arr, &arr[1], &arr[3], arr);
    printf("C: %d\n", c_result);

    int s_result = fmi_rec_s(arr, &arr[1], &arr[3], arr);
    printf("Asm: %d\n", s_result);

    return 0;
}
