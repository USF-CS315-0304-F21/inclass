.global mem_test

mem_test:
    ldrb r1, [r2, ip]
    str r1, [r2, ip, lsl #2]
