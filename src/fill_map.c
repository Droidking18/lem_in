/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaplan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 16:13:45 by dkaplan           #+#    #+#             */
/*   Updated: 2018/08/13 17:47:10 by dkaplan          ###   ########.fr       */
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
	int	j;
	int	k;
	int ret;
	char **arr;

	k = 0;
	j = 0;
	arr = ft_strsplit(str, '-');
	while (arr[k] && map[j])
	{
		j = 0;
		while (map[j])
		{
			ret = ft_strcmp(arr[k], &(map[j][1]));
			if (ret == 0)
			{
				k++;
				break ;
			}
			j++;
		}
	}
	return (k == 2 ? 1 : 0);
}

void			link_val(t_lemin map)
{
	if (dash_cnt(map.first) != 1)
		std_err(": invalid link. Too many dashes.\n");
	if (name_val(map.map, map.first) == 0)
		std_err(": bad link. Links to non existing room.\n");
	else
	{
		ft_putstr("Linking is OK");
		exit(0);
	}
}

t_lemin			fill_map(t_lemin map)
{
	return (map);
}
