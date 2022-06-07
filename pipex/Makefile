
CFLAGS = -Wall -Wextra -Werror
AR = ar rc
CC = gcc
FCTS = get_next_line.c \
get_next_line_utils.c \
ft_calloc.c \
ft_split.c \
ft_strchr.c \
ft_strdup.c \
ft_strlcat.c \
ft_strlen.c \
ft_strnstr.c \
ft_strtrim.c \
ft_printf.c \
ft_substr.c \
ft_strjoin.c \
pipex.c


OBJS = $(FCTS:.c=.o)

NAME = pipex.a

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $@ $^ pipex.h
	@$(CC) $(CFLAGS) pipex.a -o pipex -g

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: fclean clean all re