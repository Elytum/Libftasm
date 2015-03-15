section .data
    msg:
        db  `(null)\n`
    length equ $ - msg
    bn:
        db  `\n`
section .text
    global _ft_puts
    extern _ft_strlen
    extern _write

_ft_puts:
    test    rdi,    rdi
    je      null
    jmp     put_string

null:
    mov     rdi,    1
    mov     rsi,    msg
    mov     rdx,    7
    mov     rax,    0x2000004
    syscall
    ret

put_string:
    mov     rsi,    rdi
    push    rsi
    call    _ft_strlen
    mov     rdi,    1
    pop     rsi
    mov     rdx,    rax
    mov     rax,    0x2000004
    syscall
    cmp     rax,    -1
    je      out
    mov     rdi,    1
    mov     rsi,    bn
    mov     rdx,    1
    mov     rax,    0x2000004
    syscall
    ret

out:
    ret