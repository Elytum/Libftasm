section .text
	global _ft_isupper

_ft_isupper:
		cmp		rdi,		'A'
		jl		not_upper
		cmp		rdi,		'Z'
		jg		not_upper
		mov		rax,		1
		ret

not_upper:
		mov		rax,		0
		ret