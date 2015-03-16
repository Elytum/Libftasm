section .text
	global _ft_strcpy
	extern _ft_strlen

_ft_strcpy:
	mov			rdx,	rdi
	mov			rdi,	rsi
	call		_ft_strlen
	mov			rcx,	rax
	mov			rdi,	rdx
	rep			movsb
	mov byte	[rdi],	0
	mov			rax,	rdx
	ret