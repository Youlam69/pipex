
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
ft_substr.c

OBJS = $(FCTS:.c=.o)
BONUS_FCTS = ft_lstnew.c \
ft_lstadd_back.c \
ft_lstadd_front.c \
ft_lstclear.c \
ft_lstdelone.c \
ft_lstiter.c \
ft_lstlast.c \
ft_lstsize.c \
ft_lstmap.c

BONUS_OBJS = $(BONUS_FCTS:.c=.o)
NAME = libft.a

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $@ $^

bonus: $(BONUS_OBJS)
	@$(AR) $(NAME) $^

clean:
	@rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: fclean clean all re