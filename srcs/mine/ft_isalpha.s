section .text
     global _ft_isalpha

_ft_isalpha:
        cmp     rdi,   'Z'
        ja      ft_min
        cmp     rdi,   'A'
        jb      not_alpha
        mov     rax,    1
        ret

ft_min:
        cmp     rdi,   'z'
        ja      not_alpha
        cmp     rdi,   'a'
        jb      not_alpha
        mov     rax,    1
        ret

not_alpha:
        mov     rax,    0
        ret