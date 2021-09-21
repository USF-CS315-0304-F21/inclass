.global pal_rec_s

pal_rec_s:
	sub sp, sp, #16
	str lr, [sp]
	str r4, [sp, #4]
	str r5, [sp, #8]
	
	cmp r1, r2
	bge true

	ldrb r4, [r0, r1]	@ r4 is arr[start]
	ldrb r5, [r0, r2]	@ r5 is arr[end]	
	cmp r4, r5			@ if str[start] != str[end]
	bne false

	add r1, r1, #1 		@ set up start + 1 in r1
	sub r2, r2, #1 		@ set up end - 1 in r2
	bl pal_rec_s
	b done
	
true:
	mov r0, #1		@ return true
	b done

false:
	mov r0, #0		@ return false

done:
	ldr r4, [sp, #4]
	ldr r5, [sp, #8]
	ldr lr, [sp]
	add sp, sp, #16
	bx lr
