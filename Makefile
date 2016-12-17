# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aazri <aazri@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/06 12:40:11 by aazri             #+#    #+#              #
#    Updated: 2016/12/15 10:33:48 by aazri            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fillit
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror

LIB_PATH	=	./libft
LIB_BIN		= 	$(LIB_PATH)/libft.a
INCLUDES	=	-I./includes/ -I$(LIB_PATH)

SRC_PATH	=	./src/
SRC			=	$(SRC_PATH)main.c $(SRC_PATH)reader.c \
				$(SRC_PATH)analyzer.c $(SRC_PATH)positioner.c \
				$(SRC_PATH)solver.c $(SRC_PATH)error.c

OBJ			=	$(SRC:.c=.o)

$(NAME): $(OBJ)
	@make -C $(LIB_PATH)
	$(CC) -o $(NAME) $(SRC) $(INCLUDES) $(LIB_BIN)

all: $(NAME)

clean:
	@make -C $(LIB_PATH) clean
	@/bin/rm -f $(OBJ)

fclean: clean
	@make -C $(LIB_PATH) fclean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
