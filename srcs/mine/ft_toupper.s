section .text
     global _ft_toupper

_ft_toupper:
        cmp     rdi,   'a'
        jb      not_upper
        cmp     rdi,   'z'
        ja      not_upper
        add     rdi,    ('A' - 'a')
        mov     rax,    rdi
        ret

not_upper:
        mov     rax,    rdi
        ret