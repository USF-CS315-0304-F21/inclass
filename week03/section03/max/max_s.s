.global max_s

@ r0 = a, r1 = b
max_s:
    cmp r0, r1
    bgt great  @ if r0 > r1 then branch to great
    mov r0, r1
great:
    bx lr
