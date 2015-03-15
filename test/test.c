#include "test.h"
#include <stdio.h>
#include <string.h>
#define MIN_VALUE -5000000
#define MAX_VALUE 5000000
#define RANDOM_STRING_TESTS 1000
#define ERROR 0
#define	ERROR_DIF 10
#include <time.h>

/*
void	ft_bzero(void *s, size_t n);
char	*ft_strcat(char *s1, const char *s2);
int		ft_puts(const char *s);

void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
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
	int		c;

	c = dprintf(1, "Generating random strings");
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
	while (c-- > 0)
		write(1, "\b \b", 3);
	return (string);
}

void	ft_testis(compare new, compare real, char *name)
{
	int	v;
	int v1;
	int v2;
	int c;

	v = MIN_VALUE;
	c = dprintf(1, "\e[1;34mTesting %s ...\e[0m", name);
	while (42)
	{
		v1 = new(v);
		v2 = real(v + (ERROR && v > ERROR_DIF));
		if (v1 != v2)
		{
			while (c-- > 0)
				write(1, "\b \b", 3);
			dprintf(1, "\e[1;31m%s is invalid with %i : %s = %i, %s = %i\n\e[0m", name, v, name, v1, name + 3, v2);
			return ;
		}
		if (v == MAX_VALUE)
			break ;
		v++;
	}
	while (c-- > 0)
		write(1, "\b \b", 3);
	dprintf(1, "\e[1;32m%s is valid\n\e[0m", name);
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
	dprintf(1, "\e[1;32mft_strlen is valid\n\e[0m");
}

void	ft_test_strdup(char **strings)
{
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
	ptr = strings;
	while (*ptr)
	{
		s1 = strdup(*ptr);
		s2 = strdup(*ptr + (ERROR && (ptr > strings + ERROR_DIF)));
		if (strcmp(s1, s2))
		{
			while (c-- > 0)
				write(1, "\b \b", 3);
			dprintf(1, "\e[1;31mft_strdup is invalid with '%s' : ft_strdup = '%s', strdup = '%s'\n\e[0m", *ptr, s1, s2);
			free(s1), free(s2);
			return ;
		}
		free(s1), free(s2);
		ptr++;
	}
	while (c-- > 0)
		write(1, "\b \b", 3);
	dprintf(1, "\e[1;32mft_strdup is valid\n\e[0m");
}

void	ft_test_bzero(char **strings)
{
	int		len;
	int		c;
	char	**ptr;
	char	*s1;
	char	*s2;

	c = dprintf(1, "\e[1;34mTesting ft_bzero ...\e[0m");
	ptr = strings;
	while (*ptr)
	{
		s1 = (char *)malloc(sizeof(char) * (ptr - strings));
		ft_memcpy(s1, *ptr, ptr - strings);
		s2 = (char *)malloc(sizeof(char) * (ptr - strings));
		ft_memcpy(s2, *ptr, ptr - strings);
		len = rand() % (ptr - strings + (ptr - strings == 0));
		ft_bzero(s1, len);
		bzero(s2, len + (ERROR && (ptr - strings) > ERROR_DIF));
		if (ft_memcmp(s1, s2, ptr - strings))
		{
			while (c-- > 0)
				write(1, "\b \b", 3);
			dprintf(1, "\e[1;31mft_bzero is invalid with '%s' : ft_bzero = '", *ptr);
			write(1, s1, ptr - strings);
			dprintf(1, "', bzero = '");
			write(1, s2, ptr - strings);
			dprintf(1, "'\n\e[0m");
			free(s1), free(s2);
			return ;
		}
		free(s1), free(s2);
		ptr++;
	}
	while (c-- > 0)
		write(1, "\b \b", 3);
	dprintf(1, "\e[1;32mft_bzero is valid\n\e[0m");
}

void	ft_test_strcat(char **strings)
{
	int		len;
	int		c;
	char	**ptr;
	char	*tmp;
	char	*s1;
	char	*s2;

	c = dprintf(1, "\e[1;34mTesting ft_strcat ...\e[0m");
	ptr = strings;
	while (*ptr)
	{
		len = (ptr - strings) / 2;
		if (len > 0)
		{
			tmp = ft_randomstring(len);
			s1 = (char *)malloc(sizeof(char) * (len * 2 + 1));
			ft_memcpy(s1, *ptr, len);
			s1[len] = '\0';
			s2 = (char *)malloc(sizeof(char) * (len * 2 + 1));
			s2 = ft_memcpy(s2, s1, len * 2 + 1);
			strcat(s1, tmp);
			strcat(s2, tmp);
			free(tmp);	
			if (ft_memcmp(s1, s2, len * 2 + 1 + ERROR))
			{
				while (c-- > 0)
					write(1, "\b \b", 3);
				dprintf(1, "\e[1;31mft_strcat is invalid with '%s' : ft_strcat = '", *ptr);
				write(1, s1, ptr - strings);
				dprintf(1, "', strcat = '");
				write(1, s2, ptr - strings);
				dprintf(1, "'\n\e[0m");
				free(s1), free(s2);
				return ;
			}
			free(s1), free(s2);
		}
		ptr++;
	}
	while (c-- > 0)
		write(1, "\b \b", 3);
	dprintf(1, "\e[1;32mft_strcat is valid\n\e[0m");
}

void	ft_test_memset(char **strings)
{
	int		len;
	int		c;
	int		character;
	char	**ptr;
	char	*s1;
	char	*s2;

	c = dprintf(1, "\e[1;34mTesting ft_memset ...\e[0m");
	ptr = strings;
	while (*ptr)
	{
		character = rand();
		s1 = (char *)malloc(sizeof(char) * (ptr - strings));
		ft_memcpy(s1, *ptr, ptr - strings);
		s2 = (char *)malloc(sizeof(char) * (ptr - strings));
		ft_memcpy(s2, *ptr, ptr - strings);
		len = rand() % (ptr - strings + (ptr - strings == 0));
		ft_memset(s1, character, len);
		memset(s2, character, len + (ERROR && (ptr - strings) > ERROR_DIF));
		if (ft_memcmp(s1, s2, ptr - strings))
		{
			while (c-- > 0)
				write(1, "\b \b", 3);
			dprintf(1, "\e[1;31mft_memset is invalid with '%s' : ft_memset = '", *ptr);
			write(1, s1, ptr - strings);
			dprintf(1, "', memset = '");
			write(1, s2, ptr - strings);
			dprintf(1, "'\n\e[0m");
			free(s1), free(s2);
			return ;
		}
		free(s1), free(s2);
		ptr++;
	}
	while (c-- > 0)
		write(1, "\b \b", 3);
	dprintf(1, "\e[1;32mft_memset is valid\n\e[0m");
}

int		main(void)
{
	char	**strings;

	strings = ft_randomstrings(RANDOM_STRING_TESTS);
	dprintf(1, "\e[1;34m  Partie normale : \n\e[0m");
	dprintf(1, "\e[1;34m      Part 1 : \n\e[0m");
	srand(time(NULL));
	ft_test_bzero(strings);
	ft_test_strcat(strings);
	ft_testis(&ft_isalpha, &isalpha, "ft_isalpha");
	ft_testis(&ft_isdigit, &isdigit, "ft_isdigit");
	ft_testis(&ft_isalnum, &isalnum, "ft_isalnum");
	ft_testis(&ft_isascii, &isascii, "ft_isascii");
	ft_testis(&ft_isprint, &isprint, "ft_isprint");
	ft_testis(&ft_toupper, &toupper, "ft_toupper");
	ft_testis(&ft_tolower, &tolower, "ft_tolower");
	// ft_test_puts(strings);
	dprintf(1, "\e[1;34m      Part 2 : \n\e[0m");
	ft_test_strlen(strings);
	ft_test_memset(strings);
	// ft_test_memcpy(strings);
	ft_test_strdup(strings);
	// ft_stringstest(strings);
	dprintf(1, "\e[1;34m      Part 3 : \n\e[0m");
	dprintf(1, "\e[1;34m  Partie bonus : \n\e[0m");
	ft_testis(&ft_isupper, &isupper, "ft_isupper");
	ft_testis(&ft_islower, &islower, "ft_islower");
}