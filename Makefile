# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aazri <aazri@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/06 12:40:11 by aazri             #+#    #+#              #
#    Updated: 2016/12/06 17:36:17 by aazri            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fillit
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror

LIB_PATH	=	./lib/libft
LIB_BIN		= 	$(LIB_PATH)/libft.a
INCLUDES	=	-I./includes/ -I$(LIB_PATH)

SRC_PATH	=	./src/
SRC			=	$(SRC_PATH)main.c $(SRC_PATH)reader.c \
				$(SRC_PATH)analyzer.c $(SRC_PATH)positioner.c \
				$(SRC_PATH)solver.c $(SRC_PATH)error.c

OBJ			=	$(SRC:.c=.o)

all:
	@make -C $(LIB_PATH)
	@$(CC) -o $(NAME) $(FLAGS) $(SRC) $(INCLUDES) $(LIB_BIN)

clean:
	@make -C ./lib/libft clean
	@/bin/rm -f $(OBJ)

fclean: clean
	@make -C ./lib/libft fclean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
