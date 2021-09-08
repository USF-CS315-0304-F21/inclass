.global strlen_s

@ r0 = str
strlen_s:
    mov r1, #0      @ r1 is length
loop:
    ldrb r2, [r0, r1]   @ r2 = *(str + len)
    cmp r2, #0      @ reached null terminator?
    beq done
    add r1, r1, #1  @ len++
    b loop
done:
    mov r0, r1      @ set up len in r0
    bx lr
