# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkalyonc <hkalyonc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/10 12:50:31 by hkalyonc          #+#    #+#              #
#    Updated: 2022/11/01 09:46:45 by hkalyonc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libgnl.a

AR			=	ar -crs
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

SRCDIR		=	src/
SRC			=	get_next_line.c		get_next_line_utils.c

OBJDIR		=	build/
OBJFILES	=	$(SRC:.c=.o)
OBJS		=	$(OBJFILES:%=$(OBJDIR)%)

HEADERDIR	=	include/
HEADERFILES	=	get_next_line.h
HEADERS		=	$(HEADERFILES:%=$(HEADERDIR)%)

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $@ $(OBJS)
	@echo "$(NAME) compiled"

$(OBJDIR)%.o: $(SRCDIR)%.c $(HEADERS)
	@mkdir -p $(dir $@)
	@$(CC) -c $(CFLAGS) -o $@ $<

clean:
	@$(RM) $(OBJS)
	@echo "object files of $(NAME) removed"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(NAME) removed"

re: clean fclean all

.PHONY: all clean fclean re
