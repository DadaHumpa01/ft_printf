# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbrignon <dbrignon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/28 09:22:02 by dbrignon          #+#    #+#              #
#    Updated: 2021/02/12 16:18:51 by dbrignon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libftprintf.a
FLAGS = -Wall -Werror -Wextra
CC = gcc
RM = rm -f
SRCS := $(wildcard *.c)
OGG = ${SRCS:.c=.o}
AR = ar rc

all: $(NAME)

$(NAME): $(OGG)
	$(AR) $@ $^

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean: 
	$(RM) $(OGG)

fclean: clean
	$(RM) $(NAME)

re: fclean all
