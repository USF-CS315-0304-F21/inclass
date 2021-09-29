.global shift_test

shift_test:
    asr r3, r4, #2
    mov r3, r4, asr #2
    bx lr
