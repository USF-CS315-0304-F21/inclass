.global fib_rec_s

fib_rec_s:
	sub sp, sp, #16
	str lr, [sp]

	cmp r0, #1 			@ if n <= 1
	ble done

	sub r0, r0, #1		@ set up n-1
	str r0, [sp, #8]	@ preserve n-1
	bl fib_rec_s
	str r0, [sp, #4]	@ preserve retval

	ldr r0, [sp, #8]	@ restore n-1 into r0
	sub r0, r0, #1 		@ set up n-2 in r0
	bl fib_rec_s

	ldr r1, [sp, #4]	@ restore retval into r1
	add r0, r0, r1		@ return retval1 + retval2
done:
	ldr lr, [sp]
	add sp, sp, #16
	bx lr
