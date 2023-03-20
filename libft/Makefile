# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/03 13:37:57 by minkim3           #+#    #+#              #
#    Updated: 2023/03/20 15:27:26 by minkim3          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= libft.a
CC 			= cc
CFLAGS 		= -Wall -Wextra -Werror
AR          = ar -rcs
RM          = rm -f
HEADER        = libft.h
SRCS = allocate_new_memory/ft_calloc.c\
		allocate_new_memory/ft_strdup.c\
		allocate_new_memory/ft_new_string.c\
		atoi_itoa/ft_atoi.c\
		atoi_itoa/ft_itoa.c\
		atoi_itoa/ft_itoa_extension.c\
		atoi_itoa/ft_atoi_extension.c\
		change_value_pointed_by_memory/ft_memset.c\
		change_value_pointed_by_memory/ft_bzero.c\
		change_value_pointed_by_memory/ft_memcpy.c\
		change_value_pointed_by_memory/ft_memmove.c\
		change_value_pointed_by_memory/ft_strlcpy.c\
		change_value_pointed_by_memory/ft_strlcat.c\
		check_or_change_character/ft_isalpha.c\
		check_or_change_character/ft_isdigit.c\
		check_or_change_character/ft_isalnum.c\
		check_or_change_character/ft_isascii.c\
		check_or_change_character/ft_isprint.c\
		check_or_change_character/ft_toupper.c\
		check_or_change_character/ft_tolower.c\
		function_pointer/ft_striteri.c\
		function_pointer/ft_strmapi.c\
		get_next_line/get_next_line.c\
		get_next_line/get_next_line_utils.c\
		string/ft_strlen.c\
		string/ft_split.c\
		string/ft_strjoin.c\
		string/ft_substr.c\
		string/ft_strtrim.c\
		string/ft_strtok.c\
		compare_or_find_something_in_string/ft_memchr.c\
		compare_or_find_something_in_string/ft_memcmp.c\
		compare_or_find_something_in_string/ft_strchr.c\
		compare_or_find_something_in_string/ft_strrchr.c\
		compare_or_find_something_in_string/ft_strncmp.c\
		compare_or_find_something_in_string/ft_strnstr.c\
		compare_or_find_something_in_string/ft_strcmp.c\
		exit/error_return.c\
		exit/free_two_dementional_array.c\
		write/ft_putchar_fd.c\
		write/ft_putstr_fd.c\
		write/ft_putendl_fd.c\
		write/ft_putnbr_fd.c\
		write/ft_apply_flag.c\
		write/ft_apply_options.c\
		write/ft_apply_type.c\
		write/ft_check_error.c\
		write/ft_check_options.c\
		write/ft_digit_to_string.c\
		write/ft_helper.c\
		write/ft_malloc_error.c\
		write/ft_minus_and_print.c\
		write/ft_printf.c\

SRCS_BONUS = linked_list/ft_lstnew_bonus.c\
			linked_list/ft_lstadd_front_bonus.c\
			linked_list/ft_lstsize_bonus.c\
			linked_list/ft_lstlast_bonus.c\
			linked_list/ft_lstadd_back_bonus.c\
			linked_list/ft_lstdelone_bonus.c\
			linked_list/ft_lstclear_bonus.c\
			linked_list/ft_lstiter_bonus.c\
			linked_list/ft_lstmap_bonus.c
OBJS        = $(SRCS:.c=.o)
OBJS_BONUS  = $(SRCS_BONUS:.c=.o)

ifdef WITH_BONUS
	OBJECTS = $(OBJS) $(OBJS_BONUS)
else
	OBJECTS = $(OBJS)
endif

all: $(NAME)
	
$(NAME): $(OBJECTS)
	$(AR) $@ $^

bonus:
	make WITH_BONUS=1 all

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:      
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re bonus
