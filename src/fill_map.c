/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaplan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 16:13:45 by dkaplan           #+#    #+#             */
/*   Updated: 2018/08/27 11:33:04 by dkaplan          ###   ########.fr       */
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
	if (str[i - 1] && str[0] != '-')
		return (j);
	else
		return (0);
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
		std_err(RED" : room cannot link to itself.\n");
	while (arr[k] && map[j])
	{
		j = -1;
		while (map[++j])
		{
			if (ft_strcmp(arr[k], &(map[j][1])) == 0)
			{
				place[k++] = j;
				break ;
			}
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

void		link_val(t_lemin map)
{
	int **intarr;
	int ret;
	int *place;
	int comment;

	ret = 1;
	intarr = malloc_2d_int(map.s);
	while (ret)
	{
		comment = check_comment(map.in[map.count[0]]);
		if (comment == 4 || comment == 1)
			;
		else if (dash_cnt(map.in[map.count[0]]) != 1 && comment == 0)
			std_err(RED" : invalid link. Wrong format.\n");
		else if ((place = name_val(map.map, map.in[map.count[0]])) == 0
			&& comment == 0)
			std_err(RED" : bad link. Links to non existing room.\n");
		ret = get_next_line(0, &map.in[++map.count[0]]);
		intarr = fill_array(place, intarr);
	}
	complete_int_map(map, intarr);
	exit(0);
}
