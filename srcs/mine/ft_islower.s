section .text
     global _ft_islower

_ft_islower:
        cmp     rdi,   'a'
        jl      not_lower
        cmp     rdi,   'z'
        jg      not_lower
        mov     rax,    1
        ret

not_lower:
        mov     rax,    0
        ret