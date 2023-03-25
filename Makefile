# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/20 15:47:31 by minkim3           #+#    #+#              #
#    Updated: 2023/03/25 21:48:31 by minkim3          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC              = cc
CFLAGS          = -Wall -Wextra -Werror -MMD -fsanitize=address
NAME            = pipex
AR              = ar -rcs
RM              = rm -f
LIBFT           = libft/libft.a

SOURCES         = mandatory/error.c\
                  mandatory/get_path.c\
                  mandatory/fork_child.c\
                  mandatory/init_and_close.c\
                  mandatory/pipex.c
SOURCES_H       = mandatory/pipex.h
S_OBJECTS       = $(SOURCES:.c=.o)
S_EXEC          = pipex

B_SOURCES       = bonus/error_bonus.c\
                  bonus/get_path_bonus.c\
                  bonus/create_and_execute_bonus.c\
                  bonus/open_file_bonus.c\
                  bonus/pipex_bonus.c\
				  bonus/get_args_bonus.c\
				  bonus/execute_pipeline_bonus.c\
				  bonus/close_bonus.c\
				  bonus/link_pipes_bonus.c\
				  bonus/here_doc_bonus.c\
				  bonus/init_pipe_bonus.c
B_SOURCES_H     = bonus/pipex_bonus.h
B_OBJECTS       = $(B_SOURCES:.c=.o)
B_EXEC          = pipex

ifdef WITH_BONUS
	OBJECTS = $(B_OBJECTS)
	HEADER = $(B_SOURCES_H)
	EXEC = $(B_EXEC)
else
	OBJECTS = $(S_OBJECTS)
	HEADER = $(SOURCES_H)
	EXEC = $(S_EXEC)
endif

all: $(NAME)

$(NAME): $(OBJECTS) lib
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) -o $(EXEC)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

lib:
	@make -C libft

clean:
	$(RM) $(B_OBJECTS) $(B_OBJECTS:.o=.d) $(S_OBJECTS) $(S_OBJECTS:.o=.d)
	make clean -C libft

fclean: clean
	$(RM) $(NAME) $(EXEC)
	make fclean -C libft

re:
	make fclean
	make all

bonus: 
	@make WITH_BONUS=1 all

.PHONY: all lib clean fclean re bonus

-include $(OBJECTS:.o=.d)