int fmi_rec_c(int *arr, int len, int i, int max_i) {
    int max_new = max_i;

    if (i >= len) {
        return max_i;
    }

    if (arr[i] > arr[max_i]) {
        max_new = i;
    }

    return fmi_rec_c(arr, len, i + 1, max_new);
}
