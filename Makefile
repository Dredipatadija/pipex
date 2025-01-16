# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arenilla <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/21 13:17:24 by arenilla          #+#    #+#              #
#    Updated: 2024/12/21 13:17:26 by arenilla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = gcc

CFLAGS = -Wextra -Werror -Wall -I$(INC) -I$(LIBFT_DIR)

LDFLAGS	= -L$(LIBFT_DIR) -lft

INC	= ./

LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a

SRCS_DIR = ./
OBJS_DIR = objects/

SRCS_FILES = $(wildcard $(SRCS_DIR)*.c)
OBJS_FILES = $(SRCS_FILES:.c=.o)

SRCS = $(addprefix $(SRCS_DIR), $(SRCS_FILES))
OBJS = $(addprefix $(OBJS_DIR), $(OBJS_FILES))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	[ -d $(OBJS_DIR) ] || mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -sC $(LIBFT_DIR)

clean:
	rm -rf $(OBJS_DIR)
	make fclean -sC $(LIBFT_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SILENT: all clean fclean
