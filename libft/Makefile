#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aleung-c <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 15:06:11 by aleung-c          #+#    #+#              #
#    Updated: 2015/03/06 15:22:41 by aleung-c         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

SRC = ./ft_putchar.c ./ft_putnbr.c ./ft_putstr.c ./ft_strcmp.c \
	  ./ft_strdup.c ./ft_strlen.c ./ft_strcpy.c ./ft_strncpy.c \
	  ./ft_strcat.c ./ft_memalloc.c ./ft_isalpha.c ./ft_isdigit.c \
	  ./ft_isalnum.c ./ft_isascii.c ./ft_isprint.c ./ft_toupper.c \
	  ./ft_tolower.c ./ft_putchar_fd.c ./ft_putstr_fd.c ./ft_putendl.c \
	  ./ft_putendl_fd.c ./ft_putnbr_fd.c ./ft_memdel.c ./ft_strnew.c \
	  ./ft_strdel.c ./ft_atoi.c ./ft_strclr.c ./ft_striter.c \
	  ./ft_striteri.c ./ft_strchr.c ./ft_strncat.c ./ft_strstr.c \
	  ./ft_strncmp.c ./ft_memset.c ./ft_bzero.c ./ft_memcpy.c \
	  ./ft_memccpy.c ./ft_memmove.c ./ft_memchr.c ./ft_strnstr.c \
	  ./ft_strrchr.c ./ft_memcmp.c ./ft_strmap.c ./ft_strmapi.c \
	  ./ft_strequ.c ./ft_strnequ.c ./ft_strsplit.c ./ft_strsub.c \
	  ./ft_strjoin.c ./ft_strtrim.c ./ft_itoa.c ./ft_strlcat.c \
	  ./get_next_line.c ./ft_realloc.c ./ft_strsecjoin.c

SRCO = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@gcc -g -c -Wall -Wextra -Werror $(SRC)
	@ar rc $(NAME) $(SRCO)
	@ranlib $(NAME)
	@echo *Libft compiled*
clean:
	@rm -f $(SRCO)

fclean: clean
	@rm -f $(NAME)

re: fclean $(NAME)