typedef int			(*compare)(int v);
typedef int			(*output)(const char *str);
typedef void		(*outputchar)(int v);
typedef void		(*outputchar_fd)(int v, int fd);
typedef void		(*outputstr)(const char *str);
typedef void		(*outputstr_fd)(const char *str, int fd);
#include <ctype.h>
#include "../includes/libft_asm.h"