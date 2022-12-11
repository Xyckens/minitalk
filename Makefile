# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fvieira <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/09 15:44:06 by fvieira           #+#    #+#              #
#    Updated: 2022/12/09 15:44:10 by fvieira          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

LIBFT = ./libft/libft.a

CLIENT = client

SERVER = server

all: $(CLIENT) $(SERVER)

$(CLIENT):
	$(MAKE) --no-print-directory -C ./libft
	$(CC) $(CFLAGS) client.c $(LIBFT) -o client
	echo ".client created"

$(SERVER):
	$(MAKE) --no-print-directory -C ./libft
	$(CC) $(CFLAGS) server.c $(LIBFT) -o server
	echo ".server created"

clean:
	$(MAKE) clean -C ./libft
	rm -rf client server

fclean: clean
	$(MAKE) fclean -C ./libft

re: fclean all

.PHONY: all clean fclean re

.SILENT: