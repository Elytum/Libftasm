section .text
	global _ft_putstr
	extern _ft_strlen

_ft_putstr:
	mov		rsi,	rdi
	call	_ft_strlen
	mov		rdi,	1
	mov		rdx,	rax
	mov		rax,	0x2000004
	syscall
	ret