.global fact_s

fact_s:
    sub sp, sp, #8
    str lr, [sp]        @ preserve lr
    
    cmp r0, #1          @ if num == 1
    beq done
    str r0, [sp, #4]    @ preserve n
    sub r0, r0, #1      @ num = num - 1

    bl fact_s           @ recurse
    mov r1, r0          @ preserve retval
    ldr r0, [sp, #4]    @ restore num into r1
    mul r0, r0, r1      @ num * retval
done:
    ldr lr, [sp]
    add sp, sp, #8
    bx lr
