.global branch_neg

branch_neg:
    add r0, r0, #0
    add r0, r0, #0
foo:
    add r1, r1, #1
    add r1, r1, #1
    b foo
    bx lr
