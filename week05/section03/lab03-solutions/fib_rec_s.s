.global fib_rec_s

fib_rec_s:
	cmp r0, #1 			@ base case
	ble done
	
	sub sp, sp, #16		@ prologue
	str lr, [sp]

	sub r0, r0, #1		@ set up n-1 as param
	str r0, [sp, #8]	@ save n-1 for second recursion
	bl fib_rec_s
	str r0, [sp, #4]	@ squirrel away retval

	ldr r0, [sp, #8]	@ restore n-1
	sub r0, r0, #1 		@ set up n-2 for second recursion 	
	bl fib_rec_s

	ldr r1, [sp, #4]	@ restore first retval into r1
	add r0, r0, r1		@ add retvals 
	ldr lr, [sp]		@ epilogue
	add sp, sp, #16

done:
	bx lr
