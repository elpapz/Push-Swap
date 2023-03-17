# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acanelas <acanelas@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/01 04:16:32 by acanelas          #+#    #+#              #
#    Updated: 2023/03/15 21:20:18 by acanelas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/utils.c \
	srcs/utils2.c \
	srcs/sort_smaller.c \
	srcs/moves.c \
	srcs/moves2.c \
	srcs/moves3.c \
	srcs/process_input.c \
	srcs/big_boy_sort.c \
	srcs/main.c \

OBJS = $(SRCS:.c=.o)

NAME = push_swap
RM = rm -rf
LIBFT = ./libft/libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)
	
re: fclean all

.PHONY: all clean fclean re
