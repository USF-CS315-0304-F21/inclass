.global branch_pos

branch_pos:
    b foo
    add r0, r0, #0
foo:
    add r0, r0, #0
    add r1, r1, #1
    bx lr
