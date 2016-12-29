# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: videsvau <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/19 11:15:06 by videsvau          #+#    #+#              #
#    Updated: 2016/12/29 13:12:42 by videsvau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FLAGS = -Wall -Wextra -Werror

SRC = ft_columns.c \
	  ft_create_elem.c \
	  ft_dim.c \
	  ft_list_push_back.c \
	  ft_ls_error.c \
	  ft_ls_to_array.c \
	  ft_lstcount.c \
	  ft_dlistcount.c \
	  ft_manage_map.c \
	  ft_manage_tetri.c \
	  ft_open.c \
	  ft_putchar.c \
	  ft_putstr.c \
	  ft_putnbr.c \
	  ft_read.c \
	  ft_recurs.c \
	  d_list_create_elem.c \
	  ft_count_dots.c \
	  main.c 

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : 
	gcc $(FLAGS) -c $(SRC)
	gcc $(FLAGS) -o $(NAME) $(OBJ)

clean : 
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
