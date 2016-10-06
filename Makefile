# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aleung-c <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/03 15:19:00 by aleung-c          #+#    #+#              #
#    Updated: 2016/10/03 15:19:03 by aleung-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = avm

HEADER = includes/AbstractVM.hpp

SRC = src/main.cpp \
src/VMController.cpp \
src/ExceptionHandler.cpp \
src/InputController.cpp \
src/VirtualProcessor.cpp \
src/IOperandController.cpp \
src/Int8.cpp \
src/Int16.cpp \
src/Int32.cpp \
src/Float.cpp \
src/Double.cpp

OBJ = $(SRC:.cpp=.o)

LIB = ./libft/

CC = g++ -g -Wall -Werror -Wextra
#-march=native


all : Lib $(NAME) 

$(NAME) : $(OBJ)
	$(CC) -o $(NAME) $(OBJ) -L./libft/ -lft

Lib :
	make -C $(LIB)

clean :
	rm -rf $(OBJ)
	cd $(LIB) ; make clean

fclean : clean
	rm -rf $(NAME)
	cd $(LIB) ; make fclean

re : fclean all

.PHONY : all clean fclean re