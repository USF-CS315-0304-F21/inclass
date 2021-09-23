.global get_bit_s

@ r0 = num
@ r1 = which bit
get_bit_s:
    lsr r2, r0, r1      @ r2 = r0 >> r1
    and r2, r2, #1      @ r2 = r2 & #1
    mov r0, r2          @ retval
    bx lr
