/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaplan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 15:13:48 by dkaplan           #+#    #+#             */
/*   Updated: 2018/08/06 16:11:41 by dkaplan          ###   ########.fr       */
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

char	**get_map(void)
{
	char	*str;
	char	**map;
	int		i;
	int		j;

	map = (char **)malloc(sizeof(char *) * 2000);
	map = malloc_2d(map);
	j = 0;
	i = 1;
	while (i)
	{
		i = get_next_line(0, &str);
		if (name_check(str) == 1)
		{
			printf("%d", j);
			map[j][0] = j;
			j++;
			printf("\n<<%d>>\n", j);
		}
	}
	return (map);
}
