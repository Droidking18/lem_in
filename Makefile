# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkaplan <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/26 14:50:13 by dkaplan           #+#    #+#              #
#    Updated: 2018/08/15 13:29:36 by dkaplan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
SOURCES = src/get_map.c src/get_number.c src/lem_in.c src/utils.c \
			src/fill_map.c src/comp_map.c
INCLUDES = libft/libft.a

$(NAME):
	make -C libft
	gcc -Wall -Werror -Wextra $(SOURCES) $(INCLUDES) -o $(NAME)

all: $(NAME)

clean:
	make clean -C libft
	rm -f $(NAME)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all
