section .text
     global _ft_isalnum
     extern _ft_isalpha
     extern _ft_isdigit

_ft_isalnum:
		call	_ft_isalpha
        cmp     rax,   1
        je      is_alnum
        call	_ft_isdigit
        cmp     rax,   1
        je      is_alnum
        mov     rax,    0
        ret

is_alnum:
        mov     rax,    1
        ret