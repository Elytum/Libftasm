section .text
	global _ft_memcmp

_ft_memcmp:
	cmp		rdx,	0
	je		error
	mov		rcx,	rdx
	repe	cmpsb
	dec		rdi
	dec		rsi
	sub		rax,	rax
	sub		rbx,	rbx
	mov		al,		[rdi]
	mov		bl,		[rsi]
	sub		rax,	rbx
	ret

error:
	sub		rax,	rax
	mov		rax,	0
	ret