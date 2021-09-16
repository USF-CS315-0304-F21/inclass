int fmi_rec_c(int *arr, int *start, int *end, int *max)
{
    if (start > end) {
        return max - arr; 
    }

    if (*start > *max) {
        return fmi_rec_c(arr, start + 1, end, start);
    } else {
        return fmi_rec_c(arr, start + 1, end, max);
    }
}
