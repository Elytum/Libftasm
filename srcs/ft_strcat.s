section .text
    global _ft_strcat
    extern _ft_strcpy

_ft_strcat:
    mov         r8,     rdi
    sub         rax,    rax
    sub         rcx,    rcx
    not         rcx
    cld
    repne       scasb
    dec         rdi
    mov byte    [rdi],  '9'
    call        _ft_strcpy
    mov         rax,    r8
    ret
