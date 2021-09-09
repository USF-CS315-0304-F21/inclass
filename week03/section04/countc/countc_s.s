.global find_char_index_s

@ r0 = ch
@ r1 = str
@ r2 = start index
@ r3 = end index
find_char_index_s:
    sub sp, sp, #8      @ prologue
    str r4, [sp]        @ preserve r4
    str r5, [sp, #4]    @ preserve r5

    mov r4, #-1         @ r4 is return value
    mov ip, r2          @ i = start
find_loop:
    cmp ip, r3          @ reached end?
    beq find_done
    ldrb r5, [r1, ip]   @ r5 = str[i]
    cmp r5, r0          @ found?
    bne find_next
    mov r4, ip          @ rv = i
    b find_done
find_next:
    add ip, ip, #1      @ i++
    b find_loop
find_done:
    mov r0, r4          @ setup return value
    ldr r5, [sp, #4]    @ restore r5
    ldr r4, [sp]        @ restore r4
    add sp, sp, #8
    bx lr

.global count_char_s

@ r0 = char we're looking for
@ r1 = test str
@ r2 = len
count_char_s:
    sub sp, sp, #8     @ prologue
    str r4, [sp]        @ preserve r4
    str lr, [sp, #4]    @ preserve lr
    
    mov r3, #0          @ count = 0
    mov r4, #0          @ start

count_loop:
    sub sp, sp, #16
    str r0, [sp]        @ preserve scratch regs
    str r1, [sp, #4]
    str r2, [sp, #8]
    str r3, [sp, #12]
    mov r3, r2          @ set up len
    mov r2, r4          @ set up start
    bl find_char_index_s
    mov ip, r0          @ save r return value in ip
    ldr r3, [sp, #12]   @ restore scratch regs
    ldr r2, [sp, #8]
    ldr r1, [sp, #4]
    ldr r0, [sp]
    add sp, sp, #16
    
    cmp ip, #-1         @ found one?
    beq count_done
    add r3, r3, #1      @ count++
    add r4, ip, #1      @ start = r + 1
    b count_loop
count_done:
    mov r0, r3          @ set up count in r0
    ldr lr, [sp, #4]    @ restore lr
    ldr r4, [sp]        @ restore r4
    add sp, sp, #8      @ dealloc stack space
    bx lr
