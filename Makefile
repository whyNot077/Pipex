# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/20 15:47:31 by minkim3           #+#    #+#              #
#    Updated: 2023/03/23 22:40:56 by minkim3          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC              = cc
CFLAGS          = -Wall -Wextra -Werror -MMD -fsanitize=address
NAME            = pipex.a
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
                  bonus/create_pipes_and_execute_bonus.c\
                  bonus/open_file_bonus.c\
                  bonus/pipex_bonus.c\
				  bonus/get_args_bonus.c\
				  bonus/execute_pipeline_bonus.c\
				  bonus/close_bonus.c\
				  bonus/link_pipes_bonus.c\
				  bonus/here_doc_bonus.c
B_SOURCES_H     = bonus/pipex_bonus.h
B_OBJECTS       = $(B_SOURCES:.c=.o)
B_EXEC          = pipex

ifdef WITH_BONUS
	OBJECTS = $(B_OBJECTS)
	HEADER := $(B_SOURCES_H)
else
	OBJECTS = $(S_OBJECTS)
	HEADER := $(SOURCES_H)
endif

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) -o $(S_EXEC)

bonus: $(B_OBJECTS) $(LIBFT)
	$(CC) $(CFLAGS) $(B_OBJECTS) $(LIBFT) -o $(B_EXEC)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C libft

clean:
	$(RM) $(S_OBJECTS) $(S_OBJECTS:.o=.d) $(B_OBJECTS) $(B_OBJECTS:.o=.d)
	make clean -C libft

fclean: clean
	$(RM) $(NAME) $(S_EXEC) $(B_EXEC)
	make fclean -C libft

re:
	make fclean
	make all

.PHONY: all lib clean fclean re bonus

-include $(OBJECTS:.o=.d) $(B_OBJECTS:.o=.d)