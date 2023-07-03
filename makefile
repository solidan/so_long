# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acuesta- <acuesta-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/04 10:09:40 by acuesta-          #+#    #+#              #
#    Updated: 2023/06/09 12:05:55 by acuesta-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	= so_long
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g3 -fsanitize=address
SRCS	= prueba.c prueba2.c get_next_line.c get_next_line_utils.c
		
OBJS	= $(SRCS:.c=.o)
LIBS	=  -framework OpenGL -framework AppKit 
MLX		= libmlx.a
LIBFT	= libft.a
MLX_DIR	= ./minilibx
INC		= -I./includes -I$(MLX_DIR)

all: $(NAME)

$(NAME): $(OBJS) $(MLX) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(MLX) $(LIBFT) $(LIBS) -o $(NAME)

$(MLX):
	$(MAKE) -C $(MLX_DIR)
	cp $(MLX_DIR)/$(MLX) .

$(LIBFT):
	$(MAKE) -C libft
	cp libft/$(LIBFT) .

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME) $(MLX)

re: fclean all

.PHONY: all clean fclean re
