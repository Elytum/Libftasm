section .text
	global _ft_strcmp
	extern _ft_strlen
	extern _ft_memcmp

_ft_strcmp:
	push	rdi
	call	_ft_strlen
	pop		rdi
	mov		rdx,	rax
	inc		rdx
	call	_ft_memcmp
	ret