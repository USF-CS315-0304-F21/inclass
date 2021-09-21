.global pal_rec_s

@r0 = str
@r1 = start
@r2 = end
pal_rec_s:
	sub sp, sp, #8		@ prologue
	str lr, [sp]
	str r4, [sp, #4]
	
	cmp r1, r2
	bge pal_true

	ldrb r3, [r0, r1]	@ r3 = str[start]
	ldrb r4, [r0, r2]	@ r4 = str[end]
	cmp r3, r4
	bne pal_false

	add r1, r1, #1		@ set up start + 1
	sub r2, r2, #1		@ set up end - 1
	bl pal_rec_s		@ recurse
	b done
	
pal_true:
	mov r0, #1			@ return true
	b done
pal_false:
	mov r0, #0			@ return false
done:
	ldr r4, [sp, #4]	@ epilogue
	ldr lr, [sp]	
	add sp, sp, #8
	bx lr
