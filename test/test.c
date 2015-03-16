#include "test.h"
#include <stdio.h>
#include <string.h>
#define MIN_VALUE -500000
#define MAX_VALUE 500000
#define RANDOM_STRING_TESTS 10
#define ERROR 0
#define	ERROR_DIF 10
#define READ_LEN 85
#include <time.h>
#include <fcntl.h>
#define PATH "/tmp/test"
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

int		putstr2(const char *str)
{
	return (write(1, str, ft_strlen(str)));
}

int		putstr_fd2(const char *str, int fd)
{
	return (write(fd, str, ft_strlen(str)));
}

int		putchar2(const int i)
{
	return (write(1, &i, 1));
}

int		putchar_fd2(const int i, int fd)
{
	return (write(fd, &i, 1));
}

int		puts2(const char *str)
{
	if (!str)
		return (write(1, "(null)\n", 7));
	else
		return (write(1, str, ft_strlen(str)));
}

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

void	ft_test_memcpy(char **strings)
{
	int		len;
	int		c;
	char	*tmp;
	char	**ptr;
	char	*s1;
	char	*s2;

	c = dprintf(1, "\e[1;34mTesting ft_memcpy ...\e[0m");
	ptr = strings;
	while (*ptr)
	{
		len = rand() % (ptr - strings + (ptr - strings == 0));
		tmp = ft_randomstring(len);
		s1 = (char *)malloc(sizeof(char) * (ptr - strings));
		ft_memcpy(s1, *ptr, ptr - strings);
		s2 = (char *)malloc(sizeof(char) * (ptr - strings));
		ft_memcpy(s2, *ptr, ptr - strings);
		ft_memcpy(s1, tmp, len);
		memcpy(s2, tmp, len + (ERROR && (ptr - strings) > ERROR_DIF));
		free(tmp);
		if (ft_memcmp(s1, s2, ptr - strings))
		{
			while (c-- > 0)
				write(1, "\b \b", 3);
			dprintf(1, "\e[1;31mft_memcpy is invalid with '%s' : ft_memcpy = '", *ptr);
			write(1, s1, ptr - strings);
			dprintf(1, "', memcpy = '");
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
	dprintf(1, "\e[1;32mft_memcpy is valid\n\e[0m");
}

// char	*ft_testoutput(output function, char *str, size_t l, int out)
// {
// 	int		fd;
// 	int		save_fd;
// 	char	*file;
// 	char	*buffer;
// 	char	*tmp;
// 	size_t	len;
// 	size_t	v;
// 	size_t	total;

// 	remove("testing_tmp");
// 	fd = open("testing_tmp", O_RDWR | O_CREAT, S_IRUSR | S_IRGRP | S_IROTH);
// 	save_fd = dup(1);
// 	dup2(fd, out);
// 	function(str);
// 	close(out);
// 	dup2(save_fd, out);
// 	close(fd);
// 	fd = open("testing_tmp", O_RDONLY);
// 	total = 0;
// 	file = (char *)ft_memalloc(sizeof(char) * (l + 1));
// 	buffer = (char *)ft_memalloc(sizeof(char) * (READ_LEN + 1));
// 	while ((v = read(fd, buffer, 1) > 0))
// 	{
// 		memcpy(file + total, buffer, v);
// 		total += v;	
// 	}
// 	free(buffer);
// 	close(fd);
// 	remove("testing_tmp");
// 	return (file);
// }

// void	ft_test_puts(char **strings, char *name)
// {
// 	int		c;
// 	FILE	*f;
// 	char	*new;
// 	char	*original;
// 	char	**ptr;

// 	size_t n;

// 	c = dprintf(1, "\e[1;34mTesting %s ...\e[0m");
// 	ptr = strings + 1;
// 	while (*ptr)
// 	{
// 		new = ft_testoutput(&putstr, *ptr, ptr - strings, 1);
// 		original = ft_testoutput(&putstr, *ptr + (ERROR && ptr - strings > ERROR_DIF), ptr - strings, 1);
// 		dprintf(1, "New = '%s', original = '%s'\n", new, original);
// 		if (memcmp(new, *ptr, ptr - strings) || memcmp(new, original, ptr - strings))
// 		{
// 			while (c-- > 0)
// 				write(1, "\b \b", 3);
// 			dprintf(1, "\e[1;31m%s is invalid with '%s' : %s = '%s', %s = '%s'\n\e[0m", name, *ptr, name, new, name + 3, original);
// 			free(new), free(original);
// 			return ;
// 		}
// 		free(new), free(original);
// 		ptr++;
// 	}
// 	while (c-- > 0)
// 		write(1, "\b \b", 3);
// 	dprintf(1, "\e[1;32mft_puts is valid\n\e[0m");
// 	// file = freopen("testing_tmp", "r+", stdout);
// 	// remove("testing_tmp");
// }

char		*ft_getfilecontent(void)
{
	int		fd;
	char	*tmp;
	char	*str;
	char	buffer[READ_LEN + 1];
	size_t	total;
	size_t	v;
	size_t	max;

	max = 1000;
	if ((fd = open (PATH, O_RDONLY)) == -1 ||
		!(str = (char *)malloc(sizeof(char) * (max + 1))))
		return (strdup(""));
	bzero(str, max + 1);
	v = 0;
	total = 0;
	while ((v = read(fd, buffer, READ_LEN)) > 0)
	{
		if (v + total >= max)
		{
			if (!(tmp = (char *)ft_memalloc(sizeof(char) * (max * 2 + 1))))
				return (str);
			memcpy(tmp, str, max);
			free(str);
			str = tmp;
			max *= 2;
			memcpy(str + total, buffer, v);
			total += v;
		}
		memcpy(str + total, buffer, v);
		total += v;
	}
	remove(PATH);
	return (str);
}

void	ft_testfunction(int out, char multichar, int ac, void *function, char *string)
{
	int		fd;
	int		save_fd;
	char	*file;
	char	*buffer;
	char	*tmp;
	size_t	len;
	size_t	v;
	size_t	total;

	remove(PATH);
	fd = open(PATH, O_RDWR | O_CREAT, S_IRUSR | S_IRGRP | S_IROTH);
	save_fd = dup(1);
	dup2(fd, out);
	if (ac == 1)
		if (multichar)
			((outputstr)function)(string);
		else
			((outputchar)function)(*string);
	else
	{
		if (multichar)
			((outputstr_fd)function)(string, out);
		else
			((outputchar_fd)function)(*string, out);
	}
	close(out);
	dup2(save_fd, out);
	close(fd);
}

/*
// 	int		c;
// 	FILE	*f;
// 	char	*new;
// 	char	*original;
// 	char	**ptr;

// 	size_t n;

// 	c = dprintf(1, "\e[1;34mTesting %s ...\e[0m");
// 	ptr = strings + 1;
// 	while (*ptr)
// 	{
// 		new = ft_testoutput(&putstr, *ptr, ptr - strings, 1);
// 		original = ft_testoutput(&putstr, *ptr + (ERROR && ptr - strings > ERROR_DIF), ptr - strings, 1);
// 		dprintf(1, "New = '%s', original = '%s'\n", new, original);
// 		if (memcmp(new, *ptr, ptr - strings) || memcmp(new, original, ptr - strings))
// 		{
// 			while (c-- > 0)
// 				write(1, "\b \b", 3);
// 			dprintf(1, "\e[1;31m%s is invalid with '%s' : %s = '%s', %s = '%s'\n\e[0m", name, *ptr, name, new, name + 3, original);
// 			free(new), free(original);
// 			return ;
// 		}
// 		free(new), free(original);
// 		ptr++;
// 	}
// 	while (c-- > 0)
// 		write(1, "\b \b", 3);
// 	dprintf(1, "\e[1;32mft_puts is valid\n\e[0m");
// 	// file = freopen("testing_tmp", "r+", stdout);
// 	// remove("testing_tmp");
*/

void	ft_test_puts(char **strings, char *name)
{
	int		c;
	char	**ptr;
	char	*new;
	char	*original;

	c = dprintf(1, "\e[1;34mTesting %s ...\e[0m");
	ptr = strings;
	while (*ptr)
	{
		if (!(strcmp("ft_puts", name)))
			ft_testfunction(1, 1, 1, ft_puts, *ptr);
		if (!(strcmp("ft_putchar", name)))
			ft_testfunction(1, 1, 1, ft_putchar, *ptr);
		if (!(strcmp("ft_putchar_fd", name)))
			ft_testfunction(1, 1, 1, ft_putchar_fd, *ptr);
		if (!(strcmp("ft_putstr", name)))
			ft_testfunction(1, 1, 1, ft_putstr, *ptr);
		if (!(strcmp("ft_putstr_fd", name)))
			ft_testfunction(1, 1, 1, ft_putstr_fd, *ptr);
		new = ft_getfilecontent();
		if (!(strcmp("ft_puts", name)))
			ft_testfunction(1, 1, 1, puts2, *ptr);
		if (!(strcmp("ft_putchar", name)))
			ft_testfunction(1, 1, 1, putchar2, *ptr);
		if (!(strcmp("ft_putchar_fd", name)))
			ft_testfunction(1, 1, 1, putchar_fd2, *ptr);
		if (!(strcmp("ft_putstr", name)))
			ft_testfunction(1, 1, 1, putstr2, *ptr);
		if (!(strcmp("ft_putstr_fd", name)))
			ft_testfunction(1, 1, 1, putstr_fd2, *ptr);
		original = ft_getfilecontent();
		if (strcmp(new, original))
		{
			while (c-- > 0)
				write(1, "\b \b", 3);
			dprintf(1, "\e[1;31m%s is invalid with '%s' : %s = '%s', %s = '%s'\n\e[0m", name, *ptr, name, new, name + 3, original);
			free(new), free(original);
			return ;
		}
		free(new), free(original);
		ptr++;
	}
	while (c-- > 0)
		write(1, "\b \b", 3);
	dprintf(1, "\e[1;32m%s is valid\n\e[0m", name);
}

int		main(void)
{
	char	**strings;
	char	*var;

// ft_testfunction(42, 0, 1, ft_putchar, "LOLILOL");
// var = ft_getfilecontent();
// write (1, var, ft_strlen(var));
// free(var);
// return (0);
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
	dprintf(1, "\e[1;34m      Part 2 : \n\e[0m");
	ft_test_strlen(strings);
	ft_test_memset(strings);
	ft_test_memcpy(strings);
	ft_test_strdup(strings);
	dprintf(1, "\e[1;34m      Part 3 : \n\e[0m");
	dprintf(1, "\e[1;34m   Partie bonus : \n\e[0m");
	ft_testis(&ft_isupper, &isupper, "ft_isupper");
	ft_testis(&ft_islower, &islower, "ft_islower");
	ft_test_puts(strings, "ft_putchar");
	ft_test_puts(strings, "ft_putchar_fd");
	ft_test_puts(strings, "ft_putstr");
	ft_test_puts(strings, "ft_putstr_fd");
}