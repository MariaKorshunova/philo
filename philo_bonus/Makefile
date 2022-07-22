# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/14 16:43:04 by jmabel            #+#    #+#              #
#    Updated: 2022/07/04 17:25:31 by jmabel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo_bonus

HEADER		=	philo_bonus.h

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf

SRCS		=	philo_bonus.c\
				parser_init_bonus.c\
				launch_bonus.c\
				philo_processes_bonus.c\
				stop_simulation_bonus.c\
				semaphore_bonus.c\
				file_semaphore_bonus.c\
				utils_bonus.c\
				error_bonus.c

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