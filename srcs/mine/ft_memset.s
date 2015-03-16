section .text
	global _ft_memset

_ft_memset:
	mov		al,		sil
	mov		rcx,	rdx
	mov		rdx,	rdi
	rep		stosb
	mov		rax,	rdx
	ret