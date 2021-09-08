.global strlen_s

strlen_s:
    mov r1, #0      @ r1 is len
loop:
    ldrb r2, [r0, r1]   @ r2 = *(r0 + r1)
    cmp r2, #0      @ reach '\0' ?
    beq done
    add r1, r1, #1
    b loop
done:
    mov r0, r1      @ set up len retval in r0
    bx lr
