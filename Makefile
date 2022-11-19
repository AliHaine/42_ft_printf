# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#                                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayagmur <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/04 13:50:30 by ayagmur           #+#    #+#              #
#    Updated: 2022/11/04 13:50:32 by ayagmur          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRCS =	ft_printf.c \
		lib/ft_putstr.c \
		lib/ft_putchar.c \
		lib/ft_strlen.c \
		srcs/ft_itoa.c \
		srcs/ft_itoa_unsigned.c \
		srcs/isconvchar.c \
		srcs/type_manager.c \
		srcs/convert_to_basesix.c

OBJS = ${SRCS:.c=.o}

.c.o:
	${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o}

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -rf $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean
