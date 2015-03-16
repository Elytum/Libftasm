section .text
	global _ft_putchar_fd

_ft_putchar_fd:
	lea rcx, [rel buff]
	mov [rcx], dil
	mov rdi, rsi
	mov rsi, rcx
	mov rdx, 1
	mov rax, 0x2000004
	syscall
	ret

section .bss
	buff resb 1