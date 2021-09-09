.global find_char_index_s

@ r0 = char to find
@ r1 = str
@ r2 = start index
@ r3 = end index
find_char_index_s:
    sub sp, sp, #8      @ prologue
    str r4, [sp]        @ preserve r4
    str r5, [sp, #4]    @ preserve r5
    
    mov r4, #-1         @ r4 is the return value
    mov ip, r2          @ loop index = start
find_loop:
    cmp ip, r3          @ reached end?
    bge find_done
    ldrb r5, [r1, ip]   @ r5 = str[i]
    cmp r5, r0
    beq find_found
    add ip, ip, #1      @ run the loop again
    b find_loop
    
find_found:
    mov r4, ip          @ ip is the return value

find_done:
    mov r0, r4          @ set up return value in r0
    ldr r5, [sp, #4]    @ restore r5
    ldr r4, [sp]        @ restore r4
    add sp, sp, #8      @ dealloc stack space
    bx lr               @ return to caller

.global count_char_s

@ r0 = char to find
@ r1 = str
@ r2 = length
count_char_s:
    sub sp, sp, #16     @ prologue
    str r4, [sp]        @ preserve r4
    str lr, [sp, #4]    @ preserve lr
    str r5, [sp, #8]    @ preserve r5
    
    mov ip, #0          @ ip is start
    mov r4, #0          @ r4 is count

count_loop:
    sub sp, sp, #16     @ naively save all scratch regs
    str r0, [sp]
    str r1, [sp, #4]
    str r2, [sp, #8]
    str r3, [sp, #12]
    
    mov r3, r2          @ r3 is length
    mov r2, ip
    bl find_char_index_s
    mov r5, r0          @ save return value in r5
    
    ldr r3, [sp, #12]
    ldr r2, [sp, #8]
    ldr r1, [sp, #4]
    ldr r0, [sp]
    add sp, sp, #16

    cmp r5, #-1
    beq count_done
    add r4, r4, #1
    add ip, r5, #1
    b count_loop
    
count_done:
    mov r0, r4          @ set up return value
    ldr r5, [sp, #8]    
    ldr lr, [sp, #4]    @ restore lr
    ldr r4, [sp]
    add sp, sp, #16
    
    bx lr
