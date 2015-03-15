#include "test.h"
#include <stdio.h>
#include <string.h>
#define MIN_VALUE -500000
#define MAX_VALUE 500000
#define RANDOM_STRING_TESTS 20
#define ERROR 1
#define	ERROR_DIF 10
#include <time.h>


/*
void	ft_bzero(void *s, size_t n);
char	*ft_strcat(char *s1, const char *s2);
int		ft_puts(const char *s);

void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strdup(const char *s1);
void	ft_cat(int fd);
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
*/

char		*ft_randomstring(size_t len)
{
	char	*string;
	char	*ptr;

	if (!(string = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ptr = string;
	while (len--)
		*ptr++ = rand();
	*ptr = '\0';
	return (string);
}

char		**ft_randomstrings(size_t number)
{
	char	**string;
	char	**ptr;
	size_t	len;

	len = 0;
	if (!(string = (char **)malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	ptr = string;
	while (len < RANDOM_STRING_TESTS)
		*ptr++ = ft_randomstring(len++);
	*ptr = NULL;
	return (string);
}

// void	ft_stringstest(char **strings)
// {
// 	char	**ptr;

// 	ptr = strings;
// 	while (*ptr)
// 	{
// 		dprintf(1, "%s\n", *ptr);
// 		ptr++;
// 	}
// }

// void	ft_stringtest(void)
// {
// 	int	n;

// 	n = 0;
// 	while (n++ < RANDOM_STRING_TESTS)
// 		dprintf(1, "%s\n", ft_randomstring(n));
// }

void	ft_testis(compare new, compare real, char *name)
{
	int	v;
	int c;

	v = MIN_VALUE;
	c = dprintf(1, "\e[1;34mTesting %s ...\e[0m", name);
	while (42)
	{
		if (new(v) != real(v))
		{
			while (c-- > 0)
				write(1, "\b \b", 3);
			dprintf(1, "\e[1;31m%s is invalid with %i\n\e[0m", name, v);
			return ;
		}
		if (v == MAX_VALUE)
			break ;
		v++;
	}
	while (c-- > 0)
		write(1, "\b \b", 3);
	dprintf(1, "\e[1;32m\b\b\b%s is valid\n\e[0m", name);
}

void	ft_test_strlen(char **strings)
{
	char	**ptr;
	int		c;
	int		v1;
	int		v2;

	if (ft_strlen("") != strlen(""))
	{
		dprintf(1, "\e[1;31mft_strlen invalid with empty string\n\e[0m");
		return ;
	}
	c = dprintf(1, "\e[1;34mTesting ft_strlen ...\e[0m");
	ptr = strings;
	while (*ptr)
	{
		v1 = ft_strlen(*ptr);
		v2 = strlen(*ptr + (ERROR && (ptr > strings + ERROR_DIF)));
		if (v1 != v2)
		{
			while (c-- > 0)
				write(1, "\b \b", 3);
			dprintf(1, "\e[1;31mft_strlen is invalid with '%s' : ft_strlen = %i, strlen = %i\n\e[0m", *ptr, v1, v2);
			return ;
		}
		ptr++;
	}
	while (c-- > 0)
		write(1, "\b \b", 3);
	dprintf(1, "\e[1;32m\b\b\bft_strlen is valid\n\e[0m");
}

void	ft_test_strdup(char **strings)
{
	int		len;
	int		c;
	char	**ptr;
	char	*s1;
	char	*s2;

	s1 = ft_strdup("");
	s2 = strdup("");
	if (ft_memcmp(s1, s2, 1))
	{
		dprintf(1, "\e[1;31mft_strdup invalid with empty string\n\e[0m");
		free(s1), free(s2);
		return ;
	}
	c = dprintf(1, "\e[1;34mTesting ft_strdup ...\e[0m");
	len = 1;
	ptr = strings;
	while (*ptr)
	{
		s1 = ft_strdup(*ptr);
		s2 = strdup(*ptr + (ERROR && (ptr > strings + ERROR_DIF)));
		if (ft_memcmp(s1, s2, 1))
		{
			free(s1), free(s2);
			while (c-- > 0)
				write(1, "\b \b", 3);
			dprintf(1, "\e[1;31mft_strdup is invalid with '%s'\n\e[0m", *ptr);
			return ;
		}
		free(s1), free(s2);
		ptr++;
	}
}
//char	*ft_strdup(const char *s1);

int		main(void)
{
	char	**strings;

	srand(time(NULL));
	ft_testis(&ft_isalnum, &isalnum, "ft_isalnum");
	ft_testis(&ft_isalpha, &isalpha, "ft_isalpha");
	ft_testis(&ft_isascii, &isascii, "ft_isascii");
	ft_testis(&ft_isdigit, &isdigit, "ft_isdigit");
	ft_testis(&ft_islower, &islower, "ft_islower");
	ft_testis(&ft_isprint, &isprint, "ft_isprint");
	ft_testis(&ft_isupper, &isupper, "ft_isupper");
	ft_testis(&ft_toupper, &toupper, "ft_toupper");
	ft_testis(&ft_tolower, &tolower, "ft_tolower");
	strings = ft_randomstrings(RANDOM_STRING_TESTS);
	ft_test_strlen(strings);
	ft_test_strdup(strings);
	// ft_stringstest(strings);
}