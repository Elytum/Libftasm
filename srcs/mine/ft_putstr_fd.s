section .text
	global _ft_putstr_fd
	extern _ft_strlen

_ft_putstr_fd:
	push	rsi
	push	rdx
	mov		rsi,	rdi
	call	_ft_strlen
	pop		rdx
	pop		rdi
	mov		rdx,	rax
	mov		rax,	0x2000004
	syscall
	ret