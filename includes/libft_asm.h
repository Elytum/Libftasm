#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
/*Part one*/
void	ft_bzero(void *s, size_t n);
char	*ft_strcat(char *s1, const char *s2);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_puts(const char *s);

/*Part two*/
size_t	ft_strlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strdup(const char *s1);

/*Part three*/
void	ft_cat(int fd);

/*Part bonus*/
int		ft_islower(int c);
int		ft_isupper(int c);
void	*ft_memalloc(size_t size);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	ft_putchar(int c);
void	ft_putchar_fd(int c, int fd);
void	ft_putstr(char *str);
void	ft_putstr_fd(char *str, int fd);
char	*ft_strchr(const char *s, int c);
void	ft_strclr(char *s);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strnew(size_t size);

#endif