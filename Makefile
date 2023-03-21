# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/20 15:47:31 by minkim3           #+#    #+#              #
#    Updated: 2023/03/21 21:55:41 by minkim3          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			  = cc
CFLAGS        = -Wall -Wextra -Werror -MMD -fsanitize=address
NAME          = pipex.a
AR            = ar -rcs
RM            = rm -f
HEADER        = pipex.h
LIBFT         = libft/libft.a
SOURCES       = utils/error.c\
				utils/get_path.c\
				utils/fork_child.c\
				utils/init_and_close.c
S_SOURCES	= pipex.c
B_SOURCES	= get_path.c\
				fork_child.c

OBJECTS    = $(SOURCES:.c=.o)
S_OBJECTS  = $(S_SOURCES:.c=.o)
B_OBJECTS  = $(B_SOURCES:.c=.o)

all:
	make lib
	make $(NAME)
	make pipex

$(NAME): $(OBJECTS)
	$(AR) $@ $^

$(OBJECTS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

lib:
	make -C libft

clean:
	$(RM) $(OBJECTS) $(OBJECTS:.o=.d) $(S_OBJECTS) $(S_OBJECTS:.o=.d) $(B_OBJECTS) $(B_OBJECTS:.o=.d)
	make clean -C libft

fclean: clean
	$(RM) $(NAME) pipex pipex_bonus
	make fclean -C libft

re:
	make fclean
	make all

pipex: $(S_OBJECTS) $(NAME)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBFT)

pipex_bonus: $(B_OBJECTS) $(NAME)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBFT)

bonus: lib $(NAME) pipex_bonus

.PHONY: all lib clean fclean re bonus

-include $(OBJECTS:.o=.d) $(S_OBJECTS:.o=.d) $(B_OBJECTS:.o=.d)