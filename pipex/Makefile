
CFLAGS = -Wall -Wextra -Werror
AR = ar rc
CC = gcc
FCTS = ./GNxtL/get_next_line.c \
./GNxtL/get_next_line_utils.c \
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
ft_strjoin.c
# /* ft_strjoin.c \ */


OBJS = $(FCTS:.c=.o)

NAME = libft.a

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $@ $^ ./GNxtL/get_next_line.h libft.h

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: fclean clean all re