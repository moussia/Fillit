# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmottal <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/13 15:43:57 by mmottal           #+#    #+#              #
#    Updated: 2017/12/21 16:39:15 by asuissa          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

CC = gcc
NAME = fillit
CFLAGS = -Wall -Wextra -Werror
HEADER = fillit.h
CPPFLAGS = -I $(HEADER)
PATHLIB = libft/
LIB = ft
CLIB = -L $(PATHLIB) -l$(LIB)
SRC = read.c error.c fillit.c main.c
OBJS = *.o

all : $(NAME)

$(NAME) : lib
		@$(CC) $(CFLAGS) -c $(SRC) $(CPPFLAGS)
		@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(CLIB)

lib :
		@Make -C $(PATHLIB)

clean :  
		@/bin/rm -f $(OBJS)
		@Make -C $(PATHLIB) clean

fclean : clean
		@/bin/rm -f $(NAME)
		@Make -C $(PATHLIB) fclean

re : fclean all
