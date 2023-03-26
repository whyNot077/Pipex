# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjukim <minjukim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/26 13:33:36 by minjukim          #+#    #+#              #
#    Updated: 2023/03/26 14:56:25 by minjukim         ###   ########.fr        #
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
SOURCES			= pipex_bonus.c \
				  close/error_bonus.c \
				  close/close_bonus.c \
				  create_pipe_and_execute/create_and_execute_bonus.c \
				  create_pipe_and_execute/open_file_bonus.c \
				  create_pipe_and_execute/link_pipes_bonus.c \
				  create_pipe_and_execute/execute_pipeline_bonus.c \
                  get_args/get_args_bonus.c \
				  get_path/get_path_bonus.c \
				  here_doc/here_doc_bonus.c \
				  init_pipe/init_pipe_bonus.c
OBJECTS         = $(SOURCES:.c=.o)

HEADER  	    = pipex_bonus.h

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