int fact_c(int n) {
    if (n == 1) {
        return n;
    }
    return n * fact_c(n - 1);
}
