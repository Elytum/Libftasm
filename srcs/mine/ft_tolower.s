section .text
     global _ft_tolower

_ft_tolower:
        cmp     rdi,   'A'
        jb      not_upper
        cmp     rdi,   'Z'
        ja      not_upper
        add		rdi,	('a' - 'A')
        mov     rax,    rdi
        ret

not_upper:
        mov     rax,    rdi
        ret