# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grmullin <grmullin@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/29 16:11:31 by grmullin          #+#    #+#              #
#    Updated: 2024/02/07 11:17:23 by grmullin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap
FILES := main.c utils.c node_setting.c sorting.c error_handling.c init_nodes.c tiny_sort.c operations/push.c operations/reverse_rotate.c operations/rotate.c operations/swap.c final_rotations.c
OBJS := $(FILES:.c=.o)
PUSH_SWAP_H := push_swap.h.gch
CC := cc
CFLAGS := -Wall -Werror -Wextra
RM := rm -f

LIBFT_DIR := ./libft
LIBFT := $(LIBFT_DIR)/libft.a

all: $(LIBFT) $(NAME)

%.o:	%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT): 
	make -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(C_FLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean: 
	@make clean -C $(LIBFT_DIR)
	$(RM) $(OBJS) $(PUSH_SWAP_H)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)
	$(RM) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
