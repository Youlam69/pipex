# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylamraou <ylamraou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/08 11:24:45 by ylamraou          #+#    #+#              #
#    Updated: 2022/06/09 10:50:42 by ylamraou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CFLAG = -Wall -Wextra -Werror
AR = ar rcs
CC = cc
# #########SRCS#############
SRC = libft.c \
lib_ft.c \
get_next_line_utils.c \
get_next_line.c \
freeing.c \
ft_split.c \
ft_printf.c \
split.c \
cheker.c \
pipex.c

OBJS = $(SRC:.c=.o)
# #########library#############
NAME = pipex.a
# ###########EXEC###############
EXEC = pipex

all: $(EXEC)

$(EXEC) : $(NAME) 
	@$(CC) $(CFLAG) $(NAME) -g -o pipex 

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS) 

%.o : %.c
	$(CC) $(CFLAG) -c $< 

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME) 

re: fclean all

.PHONY: fclean clean all re