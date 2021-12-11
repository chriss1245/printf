# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmanzano <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/11 13:32:23 by cmanzano          #+#    #+#              #
#    Updated: 2021/12/10 10:07:42 by chris            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# MODIFY ECHO IF IN LINUX
ifeq ($(shell uname), Linux)
ECHO = echo -e
else
ECHO = echo
endif

#COLORS
GREEN = @$(ECHO) "\033[0;32m" #;4 underline
BLUE = @$(ECHO) "\033[0;34m"
PURPLE = @$(ECHO) "\033[1;35m"
CYAN = @$(ECHO) "\033[1;36m"
RESET = "\033[1;0m"

#OUTPUT 
NAME =	libftprintf.a

#REQUIRED MODULES#
LIBFT_DIR = libft
LIBFT = libft.a

#SOURCE AND OBJECTS
SRC_DIR = src
SRC = ft_printf.c
OBJ_DIR = obj
OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJ_DIR)/, $(OBJ))

#AR 
AR = ar
AR_FLAGS = crs

#COMPILER
CC = gcc
CFLAGS = -Wall -Werror -Wextra



all: create_dirs $(NAME)
	$(GREEN) Done!

$(NAME): $(LIBFT_DIR)/$(LIBFT) $(OBJS)	
	$(BLUE) Ensambling Library $(RESET)
	$(AR) $(AR_FLAGS) $(NAME) $(OBJ_DIR)/$(OBJ)

create_dirs:
	@mkdir -p $(OBJ_DIR)

$(LIBFT_DIR)/$(LIBFT):
	@make all -sC $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/$(LIBFT) $(NAME)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c 
	$(CYAN) Compiling $< $(RESET)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(PURPLE) Cleaned $(RESET)
	@rm -rf $(OBJ_DIR)
	@make clean -sC $(LIBFT_DIR)

fclean: clean
	@rm $(NAME)
	@make fclean -sC $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re bonus $(LIBFT_DIR)/%.o
