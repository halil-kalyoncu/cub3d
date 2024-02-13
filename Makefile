# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkalyonc <hkalyonc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/05 13:17:36 by hkalyonc          #+#    #+#              #
#    Updated: 2022/11/01 08:50:12 by hkalyonc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	cub3D

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
RM				=	rm -f
LIBFTDIR		=	libft/
LIBFTA			=	ft
LIBGNLDIR		=	gnl/
LIBGNLA			=	gnl
MLXDIR			=	minilibx/
INCLUDES		=	-L$(LIBFTDIR) -l$(LIBFTA) -L$(LIBGNLDIR) -l$(LIBGNLA) -L$(MLXDIR) -lmlx -framework OpenGL -framework AppKit

SRCDIR			=	src/
SRC				=	main.c\
					utils1.c\
					utils2.c\
					parser/parser.c\
					parser/parser_utils.c\
					parser/map_position.c\
					parser/map_start.c\
					parser/map_utils1.c\
					parser/map_utils2.c\
					parser/init.c\
					parser/textures.c\
					parser/color.c\
					parser/color_utils.c\
					draw/mlx_utils.c\
					draw/math.c\
					draw/raycasting.c\
					draw/draw.c\
					draw/move.c\
					draw/doors.c\
					draw/hands.c\
					draw/angles.c\
					draw/raycasting_utils.c\
					draw/draw_utils.c\
					draw/map.c\
					draw/map_utils.c\
					draw/intersection.c\
					draw/intersection_horizontal.c\
					draw/intersection_vertical.c\
					draw/intersection_utils1.c\
					draw/intersection_utils2.c

OBJDIR			=	build/
OBJFILES		=	$(SRC:.c=.o)
OBJ				=	$(OBJFILES:%=$(OBJDIR)%)

HEADERDIR		=	include/
HEADERFILES		=	cub3d.h\
					parser.h\
					draw.h
HEADER			=	$(HEADERFILES:%=$(HEADERDIR)%)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFTDIR)
	@make -C $(LIBGNLDIR)
	@make -C $(MLXDIR)
	@$(CC) $(CFLAGS) -o $@ $(OBJ) $(INCLUDES)
	@echo "$(NAME) compiled"

$(OBJDIR)%.o: $(SRCDIR)%.c $(HEADER)
	@mkdir -p $(dir $@)
	@$(CC) -c $(CFLAGS) -o $@ $<

clean:
	@$(RM) $(OBJ) $(OBJ_B)
	@make clean -C $(LIBFTDIR)
	@make clean -C $(LIBGNLDIR)
	@make clean -C $(MLXDIR)
	@echo "object files of $(NAME) removed"

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(LIBFTDIR)
	@make fclean -C $(LIBGNLDIR)
	@echo "$(NAME) removed"

re: fclean all

.PHONY: all clean fclean re
