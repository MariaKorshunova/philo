# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/14 16:43:04 by jmabel            #+#    #+#              #
#    Updated: 2022/07/01 11:26:45 by jmabel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo

HEADER		=	philo.h

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf

SRCS		=	philo.c		parser.c\
				init.c		init_philo.c\
				launch.c	stop_simulation.c\
				utils.c		error.c

OBJ			=	$(SRCS:%.c=%.o)

all			:	$(NAME)

$(NAME)		:	$(OBJ) 
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o			:	%.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -c  $<  -o $@

.PHONY		:	all clean fclean re

clean		:
	$(RM) $(OBJ)

fclean		: clean
	$(RM) $(NAME)

re			:	fclean all