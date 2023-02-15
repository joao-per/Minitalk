# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joao-per <joao-per@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 13:16:42 by joao-per          #+#    #+#              #
#    Updated: 2023/01/25 13:16:42 by joao-per         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
NAME = libftprintf.a

SRC = ft_printf variables
OBJ_DIR = Obj

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

all:$(NAME)

$(NAME): $(SRC:=.o)
		@ar rcs $(NAME) $(SRC:=.o)
		@echo "$(GREEN)ft_printf compiled!$(DEFAULT)"


bonus: fclean all

clean:
		$(RM) $(SRC:=.o)
		@echo "$(BLUE)ft_printf object files cleaned!$(DEFAULT)"

fclean: clean
		$(RM) $(NAME)
		@echo "$(RED)libftprintf.a deleted!$(DEFAULT)"

re: 	fclean $(NAME)
		@echo "$(GREEN)Cleaned and rebuilt everything for ft_printf!$(DEFAULT)"

.PHONY:		all clean fclean re