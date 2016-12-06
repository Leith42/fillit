# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aazri <aazri@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/06 12:40:11 by aazri             #+#    #+#              #
#    Updated: 2016/12/06 14:55:38 by aazri            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fillit
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror
LIB_PATH	=	./lib/libft/
LIB			=	$(LIB_PATH)libft.a
INCLUDES	=	-I$(LIB_PATH) -I./includes
SRC_PATH	=	./src/
SRC			=	$(SRC_PATH)main.c $(SRC_PATH)reader.c \
				$(SRC_PATH)analyzer.c $(SRC_PATH)positioner.c \
				$(SRC_PATH)solver.c $(SRC_PATH)error.c \

OBJ			=	$(SRC:.c=.o)

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(SRC) $(INCLUDES) -L $(LIB_PATH) -o $(NAME)
clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
