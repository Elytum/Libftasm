section .text
	global _ft_strchr
	extern _ft_strlen

_ft_strchr:
	push	rsi
	push	rdi
	call	_ft_strlen
	mov		rcx,	rax
	inc		rcx
	pop		rdi
	pop		rsi
	mov		al,		sil
	repne	scasb
	dec		rdi
	cmp		[rdi],	sil
	jne		error
	mov		rax,	rdi
	ret

error:
	sub		rax,	rax
	ret