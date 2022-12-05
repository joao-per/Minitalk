# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joao-per <joao-per@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 13:39:37 by joao-per          #+#    #+#              #
#    Updated: 2022/11/15 15:55:35 by joao-per         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variáveis

SERVER_NAME		= server
CLIENT_NAME		= client
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
RM			= rm -f

# Cores

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
	@echo "$(YELLOW)Compiling: $(DEFAULT)"
	@$(CC) $(CFLAGS) server.c ft_printf/libftprintf.a -o $(SERVER_NAME)
	@echo "$(GREEN)Server compiled! $(DEFAULT)"
	@$(CC) $(CFLAGS) client.c ft_printf/libftprintf.a -o $(CLIENT_NAME)
	@echo "$(GREEN)Client compiled! $(DEFAULT)"
	@echo "$(RED)Now bend over. $(DEFAULT)"

clean:
	@cd ft_printf && make clean
	@$(RM) $(SERVER_NAME)
	@$(RM) $(CLIENT_NAME)
	@echo "$(CYAN)Libft files cleaned. $(DEFAULT)"
	@echo "$(BLUE)Print files cleaned. $(DEFAULT)"

fclean:
	@cd ft_printf && make fclean
	@$(RM) $(SERVER_NAME)
	@$(RM) $(CLIENT_NAME)
	@echo "$(RED)LIBFT IS GONE $(DEFAULT)"
	@echo "$(RED)PRINTF IS GONE. $(DEFAULT)"
	@echo "$(GREEN)And server and client too :D $(DEFAULT)"

re: fclean all
	@echo "$(MAGENTA)I Like Children tbh. $(DEFAULT)"
