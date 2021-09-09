.global ldr_shift_s

@ r0 = arr
@ r1 = len
ldr_shift_s:
    mov ip, #0                  @ loop index i
loop:
    cmp ip, r1
    beq done
    ldr r2, [r0, ip, lsl #2]    @ r2 = arr[ip << 2]
    add r2, r2, #1                 
    str r2, [r0, ip, lsl #2]    @ arr[ip << 2] = r2
    add ip, ip, #1              @ i++
    b loop

done:
    bx lr
