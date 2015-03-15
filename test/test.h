#include <stdio.h>

typedef int			(*compare)(int v);
typedef int			(*output)(const char *str);
typedef int			(*outputchar1)(int v);
typedef void		(*outputchar2)(int v);
#include <ctype.h>
#include "../includes/libft_asm.h"
// FILE	*funopen __P2((const void *, int (*)(void *, char *, int), int (*)(void *, const char *, int), fpos_t (*)(void *, fpos_t, int), int (*)(void *)));
// int	__swbuf __P2((int, FILE *));