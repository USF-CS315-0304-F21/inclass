.global sumarr_rec_s

@ r0 = arr
@ r1 = start
@ r2 = end
sumarr_rec_s:
	sub sp, sp, #16 			@ prologue
	str lr, [sp]

	cmp r1, r2
	beq base

	str r0, [sp, #4]			@ preserve arr
	str r1, [sp, #8]
	add r1, r1, #1				@ set up start + 1
	bl sumarr_rec_s
	ldr r3, [sp, #4]			@ restore arr into r3
	ldr r1, [sp, #8]			@ restore start into r1
	ldr r1, [r3, r1, lsl #2]	@ r1 = arr[start]
	add r0, r1, r0				@ arr[start] + retval
	b done
base:
	ldr r0, [r0, r1, lsl #2]	@ return arr[start]
done:
	ldr lr, [sp]			@ epilogue
	add sp, sp, #16
	bx lr
