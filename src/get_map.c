/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaplan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 15:13:48 by dkaplan           #+#    #+#             */
/*   Updated: 2018/08/15 15:11:50 by dkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"
#include <stdio.h>

int				space_count(char *str)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			j++;
		i++;
	}
	return (j);
}

int				name_check(char *str)
{
	int	i;

	i = 0;
	if (space_count(str) != 2)
		return (0);
	while (str[i] != ' ')
		i++;
	i++;
	while (ft_isdigit(str[i]) == 1)
	{
		if (ft_isdigit(str[i] == 0 && str[i] != ' '))
			std_err("\e[0;31m : coords must be digits.\n");
		i++;
	}
	i++;
	while (ft_isdigit(str[i]) == 1)
		i++;
	if (str[i])
		std_err("\e[0;31m : bad coordinates.\n");
	return (1);
}

char			*get_name(char *str)
{
	return ((ft_strsplit(str, ' '))[0]);
}

t_lemin			get_map(void)
{
	t_lemin		map;

	map.map = malloc_2d(map.map);
	map.s = 0;
	while (get_next_line(0, &map.first))
	{
		if (map.map[map.s][0] != '#' && map.map[map.s][0] != 'L')
			map.map[map.s][0] = ' ';
		if (name_check(map.first) == 1)
		{
			map.map[map.s] = ft_strcat(map.map[map.s], get_name(map.first));
			map.s++;
		}
		else if (check_comment(map.first) == 2)
		{
			map.map[map.s][0] = '#';                 /// PROBLEM LINE
		}
		else if (check_comment(map.first) == 3)
			map.map[map.s][0] = 'L';                 /// PROBLEM LINE
		else if (check_comment(map.first) == 1 || check_comment(map.first) == 4)
			map.s++;
		else
			link_val(map);
	}
	return (map);
}
