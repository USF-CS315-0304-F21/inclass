.global fmi_rec_s

@ r0 = arr
@ r1 = len
@ r2 = cur index i
@ r3 = max index

fmi_rec_s:
    sub sp, sp, #16
    str lr, [sp]
    str r4, [sp, #4]
    str r5, [sp, #8]
    cmp r2, r1      @ if i >= len
    blt recurse
    mov r0, r3      @ set up max_i as retval
    b done
recurse:
    ldr r4, [r0, r2, lsl #2]    @ r4 = arr[i]
    ldr r5, [r0, r3, lsl #2]    @ r5 = arr[max_i]
    cmp r4, r5                  @ if arr[i] > arr[max]
    blt not_new
    mov r3, r2                  @ max_new = i
not_new:
    add r2, r2, #1
    bl fmi_rec_s

done:
    ldr lr, [sp]
    ldr r5, [sp, #8]
    ldr r4, [sp, #4]
    add sp, sp, #16
    
    bx lr
