/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaplan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 15:13:48 by dkaplan           #+#    #+#             */
/*   Updated: 2018/08/13 17:47:42 by dkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"
#include <stdio.h>

int		space_count(char *str)
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

int		name_check(char *str)
{
	int	i;

	i = 0;
	if (space_count(str) != 2)
		std_err(": incorrect amount of spaces.\n");
	while (str[i] != ' ')
		i++;
	i++;
	while (ft_isdigit(str[i]) == 1)
	{
		if (ft_isdigit(str[i] == 0 && str[i] != ' '))
				std_err(": coords must be digits.\n");
		i++;
	}
	i++;
	while (ft_isdigit(str[i]) == 1)
		i++;
	if (str[i])
		std_err(": bad coordinates.\n");
	return (1);
}

char	*get_name(char *str)
{
	return ((ft_strsplit(str, ' '))[0]);
}

t_lemin		get_map(void)
{
	t_lemin		map;
	int			j;

	map.map = (char **)malloc(sizeof(char *) * 2000);
	map.map = malloc_2d(map.map);
	j = 0;
	while (get_next_line(0, &map.first))
	{
		map.map[j][0] = ' ';
		if (name_check(map.first) == 1)
		{
			map.map[j] = ft_strjoin(map.map[j], get_name(map.first));
			j++;
		}
		else if (check_comment(map.first) == 2)
			map.map[j] = "#";
		else if (check_comment(map.first) == 3)
			map.map[j] = "L";
		else if (check_comment(map.first) == 1 || check_comment(map.first) == 4)
			j++;
		else
		{
			map.map[j] = 0;
			link_val(map);
		}
	}
	return (map);
}
