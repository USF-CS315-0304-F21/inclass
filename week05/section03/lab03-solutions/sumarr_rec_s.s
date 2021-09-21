.global sumarr_rec_s

sumarr_rec_s:
	sub sp, sp, #16				@ prologue
	str lr, [sp]

	cmp r1, r2					@ if start == end
	bne recurse
	ldr r0, [r0, r1, lsl #2]	@ return arr[start]
	b done
recurse:
	str r1, [sp, #8]			@ preserve start
	str r0, [sp, #4]			@ preserve arr
	add r1, r1, #1				@ set up start+1
	bl sumarr_rec_s
	ldr r3, [sp, #4]			@ restore arr into r3
	ldr r1, [sp, #8]			@ restore start
	ldr r3, [r3, r1, lsl #2]	@ r3 is arr[start]
	add r0, r0, r3				@ retval
done:
	
	ldr lr, [sp]				@ epilogue
	add sp, sp, #16
	bx lr
