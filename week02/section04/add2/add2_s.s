.global add2_s

@ r0 = a, r1 = b
add2_s:
	add r0, r0, r1	@ r0 = r0 + r1
	bx lr
