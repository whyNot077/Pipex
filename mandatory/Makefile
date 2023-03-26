# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjukim <minjukim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/26 13:37:23 by minjukim          #+#    #+#              #
#    Updated: 2023/03/26 14:02:18 by minjukim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC              = cc
CFLAGS          = -Wall -Wextra -Werror -MMD -fsanitize=address
NAME            = pipex
RM              = rm -f
P_LIBFT			= ../libft/
A_LIBFT         = libft.a
LIBFT			= $(addprefix $(P_LIBFT), $(A_LIBFT))

EXEC            = pipex
SOURCES			= error.c \
                  get_path.c \
                  fork_child.c \
                  init_and_close.c \
                  pipex.c
OBJECTS         = $(SOURCES:.c=.o)
HEADER  	    = pipex.h

all: lib $(NAME)

$(NAME): $(OBJECTS)
	@$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) -o $(EXEC)
	@echo -e "$(GREEN)$(EXEC) created!$(DEFAULT)"

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

lib:
	@if [ ! -f $(LIBFT) ]; then \
		make -C $(P_LIBFT); \
	fi

clean:
	$(RM) $(OBJECTS)
	$(RM) $(OBJECTS:.o=.d)
	@make clean -C $(P_LIBFT)

fclean: clean
	@$(RM) $(EXEC)
	@make fclean -C $(P_LIBFT)

re:
	@make fclean
	@make all

.PHONY: all lib clean fclean re

-include $(OBJECTS:.o=.d)

RED = \033[1;31m
PINK = \033[1;35m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
DEFAULT = \033[0m