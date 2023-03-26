# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjukim <minjukim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/20 15:47:31 by minkim3           #+#    #+#              #
#    Updated: 2023/03/26 14:57:43 by minjukim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MANDATORY		= mandatory
BONUS      	    = bonus
RM              = rm -f
CP				= cp -f
NAME			= pipex
EXEC			= $(MANDATORY)/$(NAME)
EXEC_BONUS		= $(BONUS)/$(NAME)

all: 
	@make -C $(MANDATORY)
	@$(RM) $(NAME)
	@$(CP) $(MANDATORY)/$(NAME) $(NAME)
	@echo -e "$(BLUE)copied!$(DEFAULT)"

bonus:
	@make -C $(BONUS)
	@$(CP) $(BONUS)/$(NAME) $(NAME)
	@echo -e "$(BLUE)copied!$(DEFAULT)"

clean:
	@make clean -C $(MANDATORY)
	@make clean -C $(BONUS)
	@echo -e "$(YELLOW)object files deleted!$(DEFAULT)"

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(MANDATORY)
	@make fclean -C $(BONUS)
	@echo -e "$(PINK)all deleted!$(DEFAULT)"

re:
	@make fclean
	@make all

norm:
	norminette -R CheckDefine

.PHONY: all bonus clean fclean re norm

RED = \033[1;31m
PINK = \033[1;35m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
DEFAULT = \033[0m