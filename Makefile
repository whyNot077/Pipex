# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjukim <minjukim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/20 15:47:31 by minkim3           #+#    #+#              #
#    Updated: 2023/03/26 02:37:28 by minjukim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC              = cc
CFLAGS          = -Wall -Wextra -Werror -MMD -fsanitize=address
NAME            = pipex
RM              = rm -f
LIBFT           = libft/libft.a

S_PATH		= mandatory/
SRCS         = error.c \
                  get_path.c \
                  fork_child.c \
                  init_and_close.c \
                  pipex.c
SOURCES			= $(addprefix $(S_PATH), $(SRCS))

SOURCES_H       = pipex.h
S_HEADER		= $(addprefix $(S_PATH), $(SOURCES_H))
S_OBJECTS       = $(SOURCES:.c=.o)
S_EXEC          = pipex

B_PATH			= bonus/
B_SRCS			= error_bonus.c \
                  get_path_bonus.c \
                  create_and_execute_bonus.c \
                  open_file_bonus.c \
                  pipex_bonus.c \
                  get_args_bonus.c \
                  execute_pipeline_bonus.c \
                  close_bonus.c \
                  link_pipes_bonus.c \
                  here_doc_bonus.c \
                  init_pipe_bonus.c
B_SOURCES		= $(addprefix $(B_PATH), $(B_SRCS))

B_SOURCES_H     = pipex_bonus.h
B_HEADER		= $(addprefix $(S_PATH), $(B_SOURCES_H))
B_OBJECTS       = $(B_SOURCES:.c=.o)
B_EXEC          = pipex

ifdef WITH_BONUS
	OBJECTS = $(B_OBJECTS) $(LIBFT)
	HEADER = $(B_HEADER)
	EXEC = $(B_EXEC)
else
	OBJECTS = $(S_OBJECTS)
	HEADER = $(S_HEADER)
	EXEC = $(S_EXEC)
endif

all:
	@make lib
	@make $(NAME)

bonus:
	@make WITH_BONUS=1 all

$(NAME): $(OBJECTS)
	@$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) -o $(EXEC)
	@echo -e "$(GREEN)$(EXEC) created!$(DEFAULT)"

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

lib:
	@make -C libft

norm:
	norminette -R CheckDefine

clean:
	$(RM) $(B_OBJECTS)
	$(RM) $(B_OBJECTS:.o=.d)
	$(RM) $(S_OBJECTS)
	$(RM) $(S_OBJECTS:.o=.d)
	@make clean -C libft
	@echo -e "$(YELLOW)object files deleted!$(DEFAULT)"

fclean: clean
	@$(RM) $(S_EXEC) $(B_EXEC)
	@make fclean -C libft
	@echo -e "$(PINK)all deleted!$(DEFAULT)"

re:
	@make fclean
	@make all

.PHONY: all lib clean norm fclean re bonus

-include $(S_OBJECTS:.o=.d) $(B_OBJECTS:.o=.d)

RED = \033[1;31m
PINK = \033[1;35m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
DEFAULT = \033[0m