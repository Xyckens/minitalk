# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fvieira <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/05 16:34:08 by fvieira           #+#    #+#              #
#    Updated: 2022/11/09 17:45:08 by fvieira          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

FLAG = -Wall -Wextra -Werror -I.

NAME = libft.a

SRC = ft_atoi.c \
	  ft_bzero.c \
	  ft_calloc.c \
	  ft_isalnum.c \
	  ft_isalpha.c \
	  ft_isascii.c \
	  ft_isdigit.c \
	  ft_isprint.c \
	  ft_itoa.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_memcpy.c \
	  ft_memmove.c \
	  ft_memset.c \
	  ft_putchar_fd.c \
	  ft_putendl_fd.c \
	  ft_putnbr_fd.c \
	  ft_putstr_fd.c \
	  ft_split.c \
	  ft_strlcat.c \
	  ft_strchr.c \
	  ft_strlcpy.c \
	  ft_strncmp.c \
	  ft_strdup.c \
	  ft_striteri.c \
	  ft_strjoin.c \
	  ft_strlen.c \
	  ft_strmapi.c \
	  ft_strnstr.c \
	  ft_strrchr.c \
	  ft_substr.c \
	  ft_strtrim.c \
	  ft_tolower.c \
	  ft_toupper.c \
	  ft_printf.c \
	  ft_print_pointer_fd.c \
	  ft_putchar_fd_.c \
	  ft_putnbr_fd_.c \
	  ft_putnbr_hex_fd.c \
	  ft_putstr_fd_.c \
	  ft_putlongnbr_fd.c

BONUS = ft_lstnew\
		ft_lstadd_front\
		ft_lstclear\
		ft_lstdelone\
		ft_lstiter\
		ft_lstlast\
		ft_lstmap\
		ft_lstadd_back\
		ft_lstsize

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@echo "$(NAME) created"
	@ranlib $(NAME)
	@echo "$(NAME) indexed"

%.o: %.c
	@cc $(FLAG) -c $< -o $@

clean:
	@rm -f $(OBJ) $(BONUS:=.o)
	@echo "OBJ deleted"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) deleted"

re: fclean all

bonus:	$(OBJ) $(BONUS:=.o)
	@ar rc $(NAME) $(OBJ) $(BONUS:=.o)
	@echo "$(NAME) with bonus created"
	@ranlib $(NAME)
	@echo "$(NAME) with bonus indexed"

.PHONY: all, clean, fclean, re, bonus
so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC)
	gcc -nostartfiles -shared -o libft.so $(OBJ) $(BONUS:=.o)