section .text
	global _ft_bzero
	extern _ft_memcpy

_ft_bzero:
	mov		al,		0
	mov		rcx,	rsi
	mov		rsi,	rdi
	rep		stosb
	mov		rax,	rsi
	ret
