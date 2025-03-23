# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/24 15:06:11 by pvitor-l          #+#    #+#              #
#    Updated: 2025/03/20 16:36:13 by pvitor-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -lm

DIR_LIBS = library
MLX_DIR = library/minilibx-linux/
LIB_DIR = $(DIR_LIBS)/libft
SRC_DIR = src
INC_DIR = includes

LIBFT = $(LIB_DIR)/libft.a
MLX_LIB = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
LIBFT_LIB = -L$(LIB_DIR) -lft

SRCS =	$(SRC_DIR)/main.c \
	$(SRC_DIR)/read_file.c \
	$(SRC_DIR)/draw.c \
	$(SRC_DIR)/utils.c \
	$(SRC_DIR)/errors.c \
	$(SRC_DIR)/init_points.c \
	$(SRC_DIR)/controls.c
	
OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(MLX_DIR)/libmlx.a $(NAME)

$(LIBFT):
	@make -C $(LIB_DIR)

$(MLX_DIR)/libmlx.a:
	@make -C $(MLX_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_LIB) $(LIBFT_LIB) -o $(NAME)
	@echo "FDF compilate sucess"

%.o: %.c 
	$(CC) $(CFLAGS) -I$(INC_DIR) -I$(LIB_DIR) -I$(MLX_DIR) -c $< -o $@
	@echo "compiling"

clean:
	@rm -f $(OBJS)
	@make -C $(LIB_DIR) clean
	@echo "finish clearning"

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIB_DIR) fclean

re: fclean all

.PROXY: all clean fclean re
