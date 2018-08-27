/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaplan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 11:58:54 by dkaplan           #+#    #+#             */
/*   Updated: 2018/08/27 09:02:03 by dkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include "../libft/libft.h"
# define RED "\e[0;31m"

typedef struct	s_lemin
{
	char			**map;
	int				s;
	char			*first;
	int				*arr;
	char			**in;
	int				count[1];
	long			ant;
	int				st;
	int				en;
}				t_lemin;
typedef struct	s_stack
{
	int				*stack;
	int				top;
	int				i;
	int				j;
	int				swtch;
}				t_stack;
t_lemin			get_number(void);
void			std_err(char *str);
int				check_comment(char *str);
int				check_valid(char *str);
t_lemin			get_map(t_lemin map);
char			**malloc_2d(char **map);
void			link_val(t_lemin map);
t_lemin			fill_map(t_lemin map);
int				**malloc_2d_int(int size);
void			complete_int_map(t_lemin map, int **intmap);
void			push(int *stack, int *top, int nxt_room, int *swtch);
void			pop(int *top);
void			print_ants(int *path, int size, char **map, int ants);
void			reset(int *swtch, int *j);

#endif
