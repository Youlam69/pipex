
CFLAGS = -Wall -Wextra -Werror
AR = ar rc
CC = gcc
FCTS = ft_bzero.c \
ft_calloc.c \
ft_memset.c \
ft_split.c \
ft_strchr.c \
ft_strdup.c \
ft_strjoin.c \
ft_strlcat.c \
ft_strlen.c \
ft_strnstr.c \
ft_strtrim.c \
ft_printf.c \
ft_substr.c

OBJS = $(FCTS:.c=.o)

NAME = libft.a

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $@ $^

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: fclean clean all re