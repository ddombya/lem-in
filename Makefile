# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddombya <ddombya@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/05 20:42:32 by ddombya           #+#    #+#              #
#    Updated: 2018/08/30 15:10:06 by ddombya          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

LIB = libft

LDFLAGS = -Llibft

LDLIBS = -lft

SRC_PATH = srcs

SRC_NAME =	clear_room.c\
			create_path.c\
			dijkstra_new.c\
			dijkstra_process.c\
			init_main.c\
			lst_fcts.c\
			main.c\
			print_lem-in.c\
			print_path.c\
			read_map.c

AR = ar rc

INC_LIB = -I libft

CPPFLAGS = -I includes

OBJ_PATH = obj

OBJ_NAME = $(SRC_NAME:.c=.o)

LOG_CLEAR		= \033[2K
LOG_UP			= \033[A
LOG_NOCOLOR		= \033[0m
LOG_BOLD		= \033[1m
LOG_UNDERLINE	= \033[4m
LOG_BLINKING	= \033[5m
LOG_BLACK		= \033[1;30m
LOG_RED			= \033[1;31m
LOG_GREEN		= \033[1;32m
LOG_YELLOW		= \033[1;33m
LOG_BLUE		= \033[1;34m
LOG_VIOLET		= \033[1;35m
LOG_CYAN		= \033[1;36m
LOG_WHITE		= \033[1;37m

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIB)
	@$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS) $(LDLIBS)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@echo -e "--$(LOG_CLEAR)$(LOG_VIOLET)$(NAME)$(LOG_NOCOLOR)........................ $(LOG_YELLOW)$<$(LOG_NOCOLOR)$(LOG_UP)"
	@mkdir -p $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(INC_LIB) -o $@ -c $<

clean:
	@echo -e "$(LOG_CLEAR)$(LOG_BLUE)clean obj$(LOG_NOCOLOR)"
	@make fclean -C $(LIB)
	@rm -f $(OBJ)
	@rm -rf $(OBJ_PATH) || true

fclean: clean
	@echo -e "$(LOG_CLEAR)$(LOG_BLUE)clean exe$(LOG_NOCOLOR)"
	@rm -f $(NAME)

re: fclean all
