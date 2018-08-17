# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkaplan <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/26 14:50:13 by dkaplan           #+#    #+#              #
#    Updated: 2018/08/16 17:10:30 by dkaplan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = \033[0;32m
YELLOW = \033[0;33m

NAME = lem-in
SOURCES = src/get_map.c src/get_number.c src/lem_in.c src/utils.c \
			src/fill_map.c src/comp_map.c
INCLUDES = libft/libft.a

$(NAME):
	@make -C libft
	@echo "${YELLOW}[${GREEN}BUILDING LIBFT${YELLOW}]"
	@sleep 5
	@echo "${YELLOW}[${GREEN}SORRY IF I'M SLOW, I'M ONLY A MAC${YELLOW}]"
	@sleep 1
	@gcc -Wall -Werror -Wextra $(SOURCES) $(INCLUDES) -o $(NAME)
	@echo "${YELLOW}[${GREEN}BUILDING LEM-IN${YELLOW}]"

all: $(NAME)

clean:
	@make clean -C libft
	@echo "${YELLOW}[${GREEN}REMOVING LIBFT${YELLOW}]"
	@rm -f $(NAME)
	@echo "${YELLOW}[${GREEN}REMOVING LEM-IN${YELLOW}]"

fclean: clean
	@make fclean -C libft
	@echo "${YELLOW}[${GREEN}REMOVING LIBFT OBJECT FILES${YELLOW}]"
	@rm -f $(NAME)
	@echo "${YELLOW}[${GREEN}REMOVING LEM-IN${YELLOW}]"

make:
	@echo "${YELLOW}[${GREEN}MAKING MAKE...${YELLOW}]"
	@sleep 1
	@cp Makefile ./Makefile.cp
	@echo "${YELLOW}[${GREEN}NOT REALLY SURE WHY YOU'D WANT THAT, BUT WHATEVER MAKES YOU HAPPY....${YELLOW}]"

re: fclean all
