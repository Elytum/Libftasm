section .bss
buffer:
	resb	85
section .text
	global _ft_cat
	extern _read
	extern _write

_ft_cat:
	mov		rsi,	buffer
	mov		rdx,	85			;len of read
	jmp		ft_loop				;loop

ft_loop:
	push	rdi					;save fd
	push	rdx					;save len
	push	rsi					;save buff
	mov		eax,	0x2000003	;read syscall
	syscall						;read
	jc		exitpop
	cmp		rax,	0
	jle		exitpop
	pop		rsi					;restore buff
	mov		rdi,	1			;edit fd
	mov		rdx,	rax			;edit len
	mov		eax,	0x2000004	;write syscall
	call	_write				;write
	pop		rdx					;restore len;
	pop		rdi					;restore fd
	jmp		ft_loop

exitpop:
	pop		rsi
	pop		rdx
	pop		rdi
	ret

exit:
	ret
