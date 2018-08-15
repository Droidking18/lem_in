/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaplan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 12:06:19 by dkaplan           #+#    #+#             */
/*   Updated: 2018/08/15 14:41:21 by dkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"
#include <stdio.h>

void	std_err(char *str)
{
	ft_putstr_fd("\e[1;31mError", 2);
	ft_putstr_fd("\a", 2);
	ft_putstr_fd(str, 2);
	exit(0);
}

int		check_comment(char *str)
{
	if (str[0] == '#' && str[1] != '#')
		return (1);
	else if (ft_strcmp(str, "##start") == 0)
		return (2);
	else if (ft_strcmp(str, "##end") == 0)
		return (3);
	else if (str[0] == '#')
		return (4);
	else
		return (0);
}

char	**malloc_2d(char **map)
{
	int i;

	i = 0;
	map = (char **)malloc(sizeof(char *) * 2000);
	while (i < 2001)
	{
		map[i] = (char *)malloc(sizeof(char) * 200);
		//map[i] = 0;
		i++;
	}
	return (map);
}

int		**malloc_2d_int(int size)
{
	int		**arr;
	int		i;

	i = 0;
	arr = (int **)malloc(sizeof(int *) * size);
	while (i < size)
	{
		arr[i] = (int *)malloc(sizeof(int) * size + 1);
		i++;
	}
	return (arr);
}
