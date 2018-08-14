/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaplan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 11:58:54 by dkaplan           #+#    #+#             */
/*   Updated: 2018/08/14 10:45:08 by dkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include "../libft/libft.h"

typedef struct	s_lemin
{
	char			**map;
	int				s;
	char			*first;
	int				*arr;
}				t_lemin;
int				get_number(void);
void			std_err(char *str);
int				check_comment(char *str);
int				check_valid(char *str);
t_lemin			get_map(void);
char			**malloc_2d(char **map);
void			link_val(t_lemin map);
t_lemin			fill_map(t_lemin map);
int				**malloc_2d_int(int size);

#endif
