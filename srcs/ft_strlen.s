section .text
     global _ft_strlen

_ft_strlen:
	sub		rax,	rax
	sub		rcx, 	rcx
	not		rcx
	cld
	repne	scasb
	neg		rcx
	sub		rcx,	2
	mov		rax,	rcx
	ret