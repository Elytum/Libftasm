NNAME = fts
INCLUDE = includes/
SRCPATH = ./srcs/
CFLAGS = -O3 -Wall -Werror -Wextra
C = \033[1;34m
SRCS = ft_isalpha.s \
	ft_isdigit.s	\
	ft_isascii.s	\
	ft_isprint.s	\
	ft_toupper.s	\
	ft_tolower.s	\
	ft_bzero.s		\
	ft_strcat.s		\
	ft_strlen.s		\
	ft_memset.s		\
	ft_memcpy.s		\
	ft_strdup.s		\
	ft_puts.s		\
	ft_strcpy.s		\
	ft_isupper.s	\
	ft_islower.s	\
	ft_isalnum.s	\
	ft_memcmp.s		\
	ft_strcmp.s		\
	ft_putchar.s	\
	ft_putchar_fd.s	\
	ft_putstr.s		\
	ft_putstr_fd.s	\
	ft_memalloc.s	\
	ft_strchr.s		\
	ft_strclr.s		\
	ft_strnew.s		\
	ft_cat.s


NAME = lib$(NNAME).a
CLNAME = l$(NNAME)
V = 0
SILENCE_1 :=
SILENCE_0 :=@
SILENCE = $(SILENCE_$(V))
CC = $(SILENCE)gcc
LIB = $(SILENCE)ar rc
RM = $(SILENCE)rm -rf
SRC = $(addprefix $(SRCPATH), $(SRCS))
OBJS= $(SRC:.s=.o)
SKIP_1 :=
SKIP_0 := \033[A
SKIP = $(SKIP_$(V))
U = $(C)[$(NAME)]----->\033[0m

all: $(NAME)

$(NAME):$(OBJS)
	@echo "$(U)$(C)[COMPILE:\033[1;32m DONE$(C)]\033[0m"
	@echo "$(U)$(C)[BUILD LIB]\033[0;32m"
	$(LIB) $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "$(SKIP)$(U)$(C)[BUILD  :\033[1;32m DONE$(C)]\033[0m"

%.o: %.s
	@echo "$(U)$(C)[COMPILE: \033[1;32m$<\033[A\033[0m"
	@echo "\033[0;32m"
	~/.brew/bin/nasm -f macho64 $<
	@echo "\033[1;31m [.working.]"
	@echo "$(SKIP)\033[A\033[2K$(SKIP)"
test: re
	gcc ./tests/generic.c libfts.a -I .
	./a.out 7832738

clean:
	@echo "$(U)$(C)[CLEAN]\033[0;32m"
	$(RM) $(OBJS)
	@echo "$(SKIP)$(U)$(C)[CLEAN:\033[1;32m   DONE$(C)]\033[0m"

fclean: clean
	@echo "$(U)$(C)[F-CLEAN]\033[0;32m"
	$(RM) $(NAME)
	@echo "$(SKIP)$(U)$(C)[F-CLEAN:\033[1;32m DONE$(C)]\033[0m"

re: fclean all

.PHONY: clean fclean
