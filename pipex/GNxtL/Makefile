
CFLAGS = -Wall -Wextra -Werror
AR = ar rc
CC = gcc
FCTS = get_next_line.c \
get_next_line_utils.c


OBJS = $(FCTS:.c=.o)

NAME = gtnxtln.a

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $@ $^ get_next_line.h

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: fclean clean all re