/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaplan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 11:58:54 by dkaplan           #+#    #+#             */
/*   Updated: 2018/08/06 16:03:49 by dkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include "../libft/libft.h"

int		get_number(void);
void	std_err(void);
int		check_comment(char *str);
int		check_valid(char *str);
char	**get_map(void);
char	**malloc_2d(char **map);
void	link_val(t_lemin map);

#endif
