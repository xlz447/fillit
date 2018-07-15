# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xzhu <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/12 14:55:11 by xzhu              #+#    #+#              #
#    Updated: 2018/07/12 14:55:16 by xzhu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fillit

NOC			=	\033[0m
GREEN		=	\033[0;32m
BLUE		=	\033[0;34m
RED			=	\033[0;31m

CC			=	gcc
CC_FLAGS	=	-Wall -Werror -Wextra

SRC_PATH	=	./srcs/
INC_PATH	=	./includes/
OBJ_PATH	=	./obj/
LFT_PATH	=	./libft/

SRC			=	$(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ			=	$(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC			=	$(addprefix -I,$(INC_PATH))

OBJ_NAME	=	$(SRC_NAME:.c=.o)

INC_NAME	=	fillit.h

SRC_NAME	=	input.c

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LFT_PATH)
	@$(CC) -o $(NAME) $(OBJ) -lm -L $(LFT_PATH) -lft
	@echo "$(GREEN)FILLIT ✓ Fillit ready$(NOC)"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CC_FLAGS) $(INC) -o $@ -c $<

clean:
	@make -C $(LFT_PATH) clean
	@rm -rf $(OBJ_PATH)
	@echo "$(BLUE)FILLIT ✓ Removed .o files$(NOC)"

fclean: clean
	@make -C $(LFT_PATH) fclean
	@rm -f $(NAME)
	@echo "$(RED)FILLIT ✓ Removed fillit executable$(NOC)"

re: fclean all

.PHONY: all, $(NAME), clean, fclean, re
