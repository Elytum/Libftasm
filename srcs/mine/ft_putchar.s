section .text
	global _ft_putchar

_ft_putchar:
	lea rcx, [rel buff]
	mov [rcx], dil
	mov rdi, 1
	mov rsi, rcx
	mov rdx, 1
	mov rax, 0x2000004
	syscall
	ret

section .bss
	buff resb 1