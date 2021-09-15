.global fact_s

fact_s:
    sub sp, sp, #8
    str lr, [sp]
    
    cmp r0, #1          @ if n == 1
    beq fact_done

    str r0, [sp, #4]    @ save n for later 
    sub r0, r0, #1      @ set up n-1
    bl fact_s           @ recurse
    mov r1, r0          @ save off retval
    ldr r0, [sp, #4]    @ restore n
    mul r0, r0, r1      @ n * fact(n-1)
    
fact_done:
    ldr lr, [sp]
    add sp, sp, #8
    bx lr
