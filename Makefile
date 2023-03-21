# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/20 15:47:31 by minkim3           #+#    #+#              #
#    Updated: 2023/03/21 17:40:14 by minkim3          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS        = -Wall -Wextra -Werror -MMD -fsanitize=address
NAME          = pipex.a
AR            = ar -rcs
RM            = rm -f
HEADER        = pipex.h
LIBFT         = libft/libft.a
SOURCES       = pipex.c\
                error.c\
				get_path.c
OBJECTS       = $(SOURCES:.c=.o)

all: lib $(NAME) pipex

$(NAME): $(OBJECTS)
	$(AR) $@ $^

$(OBJECTS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

lib:
	make -C libft

clean:
	$(RM) $(OBJECTS) $(OBJECTS:.o=.d)
	make clean -C libft

fclean: clean
	$(RM) $(NAME) pipex
	make fclean -C libft

re: fclean all

pipex: $(OBJECTS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

.PHONY: all lib clean fclean re

-include $(OBJECTS:.o=.d)
