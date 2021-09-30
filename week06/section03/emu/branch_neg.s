.global branch

branch:
    add r0, r0, #0
    add r0, r1, #1
    add r0, r2, #2
bar:
    add r0, r0, #0
foo:
    b branch
    b foo
    bx lr
