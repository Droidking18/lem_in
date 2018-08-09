/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaplan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 15:13:48 by dkaplan           #+#    #+#             */
/*   Updated: 2018/08/07 17:12:37 by dkaplan          ###   ########.fr       */
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
		return (0);
	while (str[i] != ' ')
		i++;
	i++;
	while (ft_isdigit(str[i]) == 1)
	{
		if (ft_isdigit(str[i] == 0 && str[i] != ' '))
				std_err();
		i++;
	}
	i++;
	while (ft_isdigit(str[i]) == 1)
		i++;
	if (str[i])
		std_err();
	return (1);
}

char	*get_name(char *str)
{
	int		i;
	char	*ret;

	ret = ft_strnew(100);
	i = 0;
	while (str[i] != ' ')
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = 7;
	ret[i + 1] = 0;
	return (ret);
}

char	**get_map(void)
{
	char	*str;
	char	**map;
	int		j;

	map = (char **)malloc(sizeof(char *) * 2000);
	map = malloc_2d(map);
	j = 0;
	while (get_next_line(0, &str))
	{
		if (name_check(str) == 1)
		{
			map[j] = ft_strjoin(map[j], get_name(str));
			j++;
		}
		else if (check_comment(str) == 2)
			map[j] = "#";
		else if (check_comment(str) == 3)
			map[j] = "L";
		else if (check_comment(str) == 1 || check_comment(str) == 4)
			j++;
		else
			link_val(map);
	}
	map[j] = NULL;
	j = 0;
	while (map[j])
	{
		printf("<<%s\n", map[j]);
		j++;
	}
	return (map);
}
