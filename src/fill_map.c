/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaplan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 16:13:45 by dkaplan           #+#    #+#             */
/*   Updated: 2018/08/08 16:23:06 by dkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

int			dash_cnt(char *str)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '-')
			j++;
		i++;
	}
	return (j);
}

int			name_val(char **map, char *str)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	j = 1;
	i = 0;
	while (map[k])
	{
		while (map[k][j] == str[i])
		{
			i++;
			if (str == 0 && map[k][j] == 0)
				return (1);
		}
		k++;
	}
	return (0);
}

void			link_val(t_lemin map)
{
	if (dash_cnt(map.first) != 1)
		std_err();
	if (name_val(map.map, map,first) == 0)
		std_err();
	else
		ft_putstr("Linking is OK");
}

t_lemin			fill_map(t_lemin map)
{
	return (map);
}


