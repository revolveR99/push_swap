# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zabdulza <zabdulza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/10 09:54:52 by zabdulza          #+#    #+#              #
#    Updated: 2023/08/19 12:50:51 by zabdulza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIBFT_DIR = libft
LIBFT = ./libft/libft.a
CFLAGS = -Wall -Wextra -Werror -g 
RM = rm -rf
SRC	= $(addprefix ./sources/,$(SRCS))
CC = cc 
SRCS = helpers.c movers.c sorting.c main.c
OBJ = $(SRC:.c=.o)

GREEN = \033[32m
PINK = \033[38;5;197m
RESET = \033[0m


all: $(LIBFT) $(NAME) 
	@echo "$(PINK)Bro it is ready and waiting for you!$(RESET)"
	@echo "$(GREEN)For testing 4 random numbers ./push_swap 1 2 3 4 or not going to work cause it is already in order try reverse$(RESET)"

$(LIBFT):
	@make -s -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L./$(LIBFT_DIR) -lft

$(OBJ): $(SRC)
	@$(CC) $(CFLAGS) -c $? -I./$(LIBFT_DIR)
	@mv *.o sources

clean:	
	@$(RM) sources/*.o 
	@make -s -C $(LIBFT_DIR) clean

fclean:	clean
	@$(RM) $(NAME)
	@make -s -C $(LIBFT_DIR) fclean

re:	fclean all clean

.PHONY: all clean fclean re
