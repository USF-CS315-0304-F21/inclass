.global mem_test

mem_test:
    str lr, [sp]
    ldr lr, [sp]
    @ldr r0, [r1, lsl #2]
    @ldr r0, [r1, lsl ip]
    @ldrb r0, [r1, ip]
    @strb r0, [r2, ip]
