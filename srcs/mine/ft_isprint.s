section .text
     global _ft_isprint

_ft_isprint:
        cmp     rdi,   32
        jb      not_print
        cmp     rdi,   126
        ja      not_print
        mov     rax,    1
        ret

not_print:
        mov     rax,    0
        ret