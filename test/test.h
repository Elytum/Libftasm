typedef int			(*compare)(int v);
typedef int			(*output)(const char *str);
typedef void		(*outputchar)(int v);
typedef void		(*outputchar_fd)(int v, int fd);
#include <ctype.h>
#include "../includes/libft_asm.h"