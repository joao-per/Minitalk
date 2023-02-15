# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joao-per <joao-per@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/14 23:31:02 by joao-per          #+#    #+#              #
#    Updated: 2023/02/14 23:38:18 by joao-per         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
SERVER_NAME = server
CLIENT_NAME = client

CC = gcc
CFLAGS = -Wall -Werror -Wextra -I.

RM = rm -f

# Colors

DEFAULT = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

all: $(SERVER_NAME)
$(SERVER_NAME):
	@cd ft_printf && make all
	@$(CC) $(CFLAGS) -g server.c ft_printf/libftprintf.a  ft_printf/ft_atoi.c -o $(SERVER_NAME)
	@echo "$(GREEN)Server compiled! $(DEFAULT)"
	@$(CC) $(CFLAGS) -g client.c ft_printf/libftprintf.a ft_printf/ft_atoi.c -o $(CLIENT_NAME)
	@echo "$(GREEN)Client compiled! $(DEFAULT)"

clean:
	@cd ft_printf && make clean
	@echo "$(BLUE)Print files cleaned. $(DEFAULT)"

fclean:	clean
	@cd ft_printf && make fclean
	@$(RM) $(SERVER_NAME)
	@$(RM) $(CLIENT_NAME)
	@echo "$(RED)Everything is cleaned $(DEFAULT)"

re: fclean all
