.global ldr_shift_s

@ r0 = arr, r1 = len
ldr_shift_s:
    mov ip, #0                  @ loop index
loop:
    cmp ip, r1                  @ reached len?
    beq done
    ldr r2, [r0, ip, lsl #2]    @ r2 = arr[ip]
    lsl r2, #1                  @ r2 <<= 1
    str r2, [r0, ip, lsl #2]    @ arr[ip] = r2
    add ip, ip, #1              @ increment loop index
    b loop
done:
    bx lr
