/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaplan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 16:13:45 by dkaplan           #+#    #+#             */
/*   Updated: 2018/08/16 10:14:05 by dkaplan          ###   ########.fr       */
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

int			*name_val(char **map, char *str)
{
	int		j;
	int		k;
	char	**arr;
	int		*place;

	place = (int*)malloc(sizeof(int) * 2);
	k = 0;
	j = 0;
	arr = ft_strsplit(str, '-');
	if (ft_strcmp(arr[0], arr[1]) == 0)
		std_err(red" : room cannot link to itself.\n");
	while (arr[k] && map[j])
	{
		j = 0;
		while (map[j])
		{
			if (ft_strcmp(arr[k], &(map[j][1])) == 0)
			{
				place[k++] = j;
				break ;
			}
			j++;
		}
	}
	return (k == 2 ? place : 0);
}

int			**fill_array(int *place, int **intarr)
{
	intarr[place[0]][place[1]] = 1;
	intarr[place[1]][place[0]] = 1;
	return (intarr);
}

void		print(int **intarr, int *place)
{
	printf("<<<<%d ", place[0]);
	printf("%d>>>>\n", place[1]);
	printf("%d ", intarr[0][0]);
	printf("%d ", intarr[0][1]);
	printf("%d\n", intarr[0][2]);
	printf("%d ", intarr[1][0]);
	printf("%d ", intarr[1][1]);
	printf("%d\n", intarr[1][2]);
	printf("%d ", intarr[2][0]);
	printf("%d ", intarr[2][1]);
	printf("%d\n", intarr[2][2]);
}

void		link_val(t_lemin map)
{
	int **intarr;
	int ret;
	int i;
	int *place;

	i = 0;
	ret = 1;
	intarr = malloc_2d_int(map.s);
	while (ret)
	{
		if (dash_cnt(map.first) != 1)
			std_err(red" : invalid link. Wrong format.\n");
		if ((place = name_val(map.map, map.first)) == 0)
			std_err(red" : bad link. Links to non existing room.\n");
		else
		{
			ret = get_next_line(0, &map.first);
			intarr = fill_array(place, intarr);
			i++;
		}
	}
	complete_int_map(map, intarr);
	exit(0);
}
