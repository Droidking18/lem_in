/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaplan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 16:13:45 by dkaplan           #+#    #+#             */
/*   Updated: 2018/08/10 12:11:59 by dkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"
#include <stdio.h>

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
		while (map[k][j] == str[i] && str[i])
		{
			i++;
			j++;
			if (map[k][j] != str[i])
			{
				printf("\n\n<<%c>>, <<%c>>\n\n", str[i], map[k][j]);
				return (0);
			}
		}
		k++;
		j = 1;
		i = 0;
	}
	return (1);
}

void			link_val(t_lemin map)
{
	if (dash_cnt(map.first) != 1)
		std_err();
	if (name_val(map.map, map.first) == 0)
		std_err();
	else
		ft_putstr("Linking is OK");
	return ;
}

t_lemin			fill_map(t_lemin map)
{
	return (map);
}
