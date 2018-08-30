# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddombya <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/29 17:18:53 by ddombya           #+#    #+#              #
#    Updated: 2018/08/29 17:40:22 by ddombya          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
NAME = libft.a
LIBFT = $(NAME)

SRC_PATH = ./
OBJ_PATH = obj/
INC_PATH = ./includes/
LIB_PATH = ./

SRC_LIBFT = \
			ft_atoi.c \
			ft_bzero.c \
			ft_char_to_str.c \
			ft_countchar.c \
			ft_error.c \
			ft_find_conv.c \
			ft_find_flags.c \
			ft_find_mod.c \
			ft_find_prc.c \
			ft_find_width.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_isspace.c \
			ft_itoa_base.c \
			ft_itoa_bin.c \
			ft_itoa_oct.c \
			ft_itoa.c \
			ft_lstadd.c \
			ft_lstdel.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_lstnew.c \
			ft_memalloc.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memdel.c \
			ft_memmove.c \
			ft_memset.c \
			ft_print_bin.c \
			ft_print_char.c \
			ft_print_hexa.c \
			ft_print_int.c \
			ft_print_mod.c \
			ft_print_octal.c \
			ft_print_prc.c \
			ft_print_ptr.c \
			ft_print_str.c \
			ft_print_u_int.c \
			ft_print_wchar.c \
			ft_print_wstr.c \
			ft_printf.c \
			ft_putchar.c \
			ft_putchar_fd.c \
			ft_putendl.c \
			ft_putendl_fd.c \
			ft_putnbr.c \
			ft_putnstr.c \
			ft_putnbr_fd.c \
			ft_putstr.c \
			ft_putstr_fd.c \
			ft_strcat.c \
			ft_strchr.c \
			ft_strclr.c \
			ft_strcmp.c \
			ft_strcpy.c \
			ft_strdel.c \
			ft_strdup.c \
			ft_strequ.c \
			ft_strisalnum.c \
			ft_strisdigit.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strjoin_free.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlen.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strncat.c \
			ft_strncmp.c \
			ft_strncpy.c \
			ft_strnequ.c \
			ft_strnew.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strsplit_free.c \
			ft_strsplit_len.c \
			ft_strsplit.c \
			ft_strstr.c \
			ft_strsub.c \
			ft_strtrim.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_wc_to_str.c \
			get_next_line.c \

OBJ_LIBFT = $(SRC_LIBFT:.c=.o)
	LIBFTC = $(addprefix $(SRC_PATH),$(SRC_LIBFT))
	LIBFTO = $(addprefix $(OBJ_PATH),$(OBJ_LIBFT))

all: $(NAME)

$(OBJ_PATH) :
	@mkdir $(OBJ_PATH)

obj/%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_PATH)

$(NAME) : $(OBJ_PATH) $(LIBFTO)
	@ar rc $(NAME) $(LIBFTO)
	@ranlib $(NAME)

.PHONY: clean fclean

clean:
	@rm -rf $(OBJ_PATH)

fclean: clean
	@rm -f $(NAME)

re: fclean all
