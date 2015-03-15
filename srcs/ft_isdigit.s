section .text
     global _ft_isdigit

_ft_isdigit:
        cmp     rdi,   '0'
        jl      not_digit
        cmp     rdi,   '9'
        jg      not_digit
        mov     rax,    1
        ret

not_digit:
        mov     rax,    0
        ret