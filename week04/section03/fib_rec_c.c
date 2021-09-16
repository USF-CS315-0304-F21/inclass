int fib_rec_c(int n) {
    // save link register
    
    if (n <= 1) {
        return n;
    }
    return fib_rec_c(n - 1) + fib_rec_c(n - 2);

    // when fib_rec_s starts, r0 == n

    // save r0 to stack
    
    // set up n-1 in r0
    // bl fib_rec_s
    // squirrel away retval [code at return address]

    // set up n-2 in r0
    // bl fib rec_s
    // code at return address
    
    // restore link register
    // bx lr
}
