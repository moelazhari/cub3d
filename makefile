# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mazhari <mazhari@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/06 16:18:39 by mazhari           #+#    #+#              #
#    Updated: 2022/10/04 16:29:39 by mazhari          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= gcc
CFLAGS = -Wall -Werror -Wextra
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit
NAME= cub3D

INCLUDES= ./includes
HEDEAR= $(INCLUDES)/cub3d.h\
		$(INCLUDES)/get_next_line.h

LIBFT_DIR = ./libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

B_DIR = ./build


GNL= $(addprefix gnl/, get_next_line get_next_line_utils)
PARS= $(addprefix pars/, pars_file get_texture get_color get_map check_map)
GAME= $(addprefix game/, generate_game moves ray_casting ray_casting1) 
SRC= $(addprefix src/, main ft_exit $(PARS) $(GAME))
FILES= $(SRC) $(GNL)
OBJS= $(addprefix $(B_DIR)/, $(FILES:=.o))

all: $(NAME)

$(B_DIR)/%.o: %.c $(LIBFT_LIB) $(HEDEAR)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(INCLUDES)  -c $< -o $@

$(NAME): $(OBJS) $(HEDEAR)
	$(CC)  $(MLXFLAGS) $(LIBFT_LIB) $(OBJS) -o $(NAME)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS)
	rm -rf $(B_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean f re 