# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: syoshika <syoshika@student.42tokyo.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/14 20:18:35 by syoshika          #+#    #+#              #
#    Updated: 2021/04/03 20:32:37 by syoshika         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3D
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
SRCS		=	./srcs/main.c \
				./srcs/check/arg_error.c \
				./srcs/check/check_params.c \
				./srcs/check/double_spec.c \
				./srcs/check/error.c \
				./srcs/configration/player.c \
				./srcs/configration/sprite.c \
				./srcs/end/end.c \
				./srcs/read_cubfile/map.c \
				./srcs/read_cubfile/read_cub.c \
				./srcs/read_cubfile/spec_fc.c \
				./srcs/read_cubfile/spec_path.c \
				./srcs/read_cubfile/spec_r.c \
				./srcs/read_cubfile/floodfill.c \
				./srcs/mlx/key_hook.c \
				./srcs/mlx/loop.c \
				./srcs/mlx/movement.c \
				./srcs/raycasting/ray_casting.c \
				./srcs/raycasting/ray_check.c \
				./srcs/render/render_sprite.c \
				./srcs/render/sprite_sort.c \
				./srcs/render/render_utils.c \
				./srcs/render/render_wall.c \
				./srcs/render/render_tex_color.c \
				./srcs/setup/init_info.c \
				./srcs/setup/init_structure.c \
				./srcs/texture/open.c \
				./srcs/utils/strs_length.c \
				./srcs/utils/char_digits.c \
				./srcs/utils/my_atoi.c \
				./srcs/utils/check_comma.c \
				./srcs/utils/all_free.c \
				./srcs/export/export.c
SRCS		+=	./Get_next_line/get_next_line.c \
				./Get_next_line/get_next_line_utils.c 
			
OBJS		=	$(SRCS:.c=.o)
PREPROS		=	$(SRCS:.c=.d)
INCLUDE		=	-I./includes
COMPILE_OPT	=	-lmlx -framework OpenGL -framework Appkit

all:		$(NAME)

-include	$(PREPROS)

libft:
			make --directory=./libft

.c.o:
			$(CC) -c -MMD $(CFLAGS) $(INCLUDE) $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			make --directory=./libft
			make --directory=./minilibX-mms_20200219
			cp minilibX-mms_20200219/libmlx.dylib ./libmlx.dylib
			$(CC) $(SRCS) libmlx.dylib $(INCLUDE) -L./libft -lft -L./minilibX-mms_20200219 $(COMPILE_OPT) -o $(NAME)

clean:
			make clean --directory=./libft
			make clean --directory=./minilibX-mms_20200219
			$(RM) $(OBJS) $(PREPROS)

fclean:		clean
			make fclean --directory=./libft
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all fclean clean re libft
