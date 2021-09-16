int fib_rec_c(int n) {
    if (n <= 1) {
        return n;
    }
    return fib_rec_c(n - 1) + fib_rec_c(n - 2);

    // preserves r0 to the stack
    // r0 to be n-1
    // bl fib_rec_s
    // r0 contain retval from first recursion
    // set aside retval
    
    // restore r0 from stack
    // r0 to be n-2
    // fib_rec_s

    // r0 = first retval + second retval
}
