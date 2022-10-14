# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/14 09:57:24 by chanheki          #+#    #+#              #
#    Updated: 2022/10/14 09:57:26 by chanheki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= cc
CFLAGS	= -Wall -Wextra -Werror

AR	= ar
ARFLAGS	= rcs

RM	= rm -f

NAME	= libftprintf.a

SRCS	= ft_printf.c _ft_printf.c

OBJS	= $(SRCS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	$(AR) $(ARFLAGS) $@ $^

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:
	make fclean
	make all

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY:	all bonus clean fclean re
