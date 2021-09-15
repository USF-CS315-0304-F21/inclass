int fact_c(int num) {
    if (num == 1) {
        return num;
    }
    return num * fact_c(num - 1);
}
