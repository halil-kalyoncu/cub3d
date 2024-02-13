# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkalyonc <hkalyonc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/25 14:05:53 by hkalyonc          #+#    #+#              #
#    Updated: 2022/11/01 09:47:34 by hkalyonc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

AR			=	ar -crs
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

SRCDIR		=	src/
SRC			=	ft_isalnum.c	ft_isprint.c	ft_memcmp.c\
				ft_putchar_fd.c	ft_strlcat.c	ft_strncmp.c\
				ft_substr.c		ft_atoi.c		ft_isalpha.c\
				ft_itoa.c		ft_memcpy.c		ft_putendl_fd.c\
				ft_strchr.c		ft_strlcpy.c	ft_strnstr.c\
				ft_tolower.c	ft_bzero.c		ft_isascii.c\
				ft_memccpy.c	ft_memmove.c	ft_putnbr_fd.c\
				ft_strdup.c		ft_strlen.c		ft_strrchr.c\
				ft_toupper.c	ft_calloc.c		ft_isdigit.c\
				ft_memchr.c		ft_memset.c		ft_putstr_fd.c\
				ft_strjoin.c	ft_strmapi.c	ft_striteri.c\
				ft_strtrim.c	ft_split.c		ft_lstadd_back.c\
				ft_lstadd_front.c	ft_lstclear.c	ft_lstdelone.c\
				ft_lstiter.c	ft_lstlast.c	ft_lstmap.c\
				ft_lstnew.c		ft_lstsize.c\
				ft_abs.c		ft_itoa_base.c	ft_uitoa_base.c\
				ft_luitoa_base.c	ft_strc.c	ft_strrev.c\
				ft_uitoa.c		ft_intdigits.c\
				ft_atol.c\
				ft_free_2d_array_nullterminated.c	ft_free_2d_array.c\
				ft_free_3d_array_nullterminated.c	ft_free_void_ptr.c\
				ft_islowercase.c	ft_putstr_lowercase.c

OBJDIR		=	build/
OBJFILES	=	$(SRC:.c=.o)
OBJS		=	$(OBJFILES:%=$(OBJDIR)%)

HEADERDIR	=	include/
HEADERFILES	=	libft.h
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
