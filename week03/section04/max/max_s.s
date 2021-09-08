.global max_s

@ r0 = a, r1 = b
max_s:
    cmp r0, r1
    bgt done        @ r0 > r1, nothing else to do
    mov r0, r1      @ r1 <= r0, set up r1 as max
done:
    bx lr
