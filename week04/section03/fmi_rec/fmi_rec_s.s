.global fmi_rec_s

@ r0 = ptr to arr
@ r1 = ptr to start
@ r2 = ptr to end
@ r3 = ptr to max
fmi_rec_s:
    sub sp, sp, #16
    str lr, [sp]
    str r4, [sp, #4]
    str r5, [sp, #8]
    
    cmp r1, r2
    ble compare
    sub r0, r3, r0
    lsr r0, r0, #2
    b done
compare:
    ldr r4, [r1]        @ r4 = *start
    ldr r5, [r3]        @ r5 = *max
    cmp r4, r5
    ble not_greater
    mov r3, r1          @ set up start in r3
    add r1, r1, #4      @ set up start + 1 in r1
    bl fmi_rec_s        @ recurse
    b done              @ retval is in r0
not_greater:
    add r1, r1, #4      @ setup start + 1 in r1
    bl fmi_rec_s        @ recurse
done:
    ldr r5, [sp, #8]
    ldr r4, [sp, #4]
    ldr lr, [sp]
    add sp, sp, #16
    bx lr
