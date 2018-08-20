/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaplan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 13:19:16 by dkaplan           #+#    #+#             */
/*   Updated: 2018/08/20 17:38:28 by dkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"
#include <stdio.h>

t_lemin		map_check(t_lemin *map)
{
	int i;

	map->st = 0;
	map->en = 0;
	i = 0;
	while (i < map->s)
	{
		if (map->map[i][0] == '#')
			map->st++;
		else if (map->map[i][0] == 'L')
			map->en++;
		i++;
	}
	if (map->en != 1 || map->st != 1)
		std_err(RED": Not sure where ants start/ end\n");
	i = 0;
	while (i < map->s)
	{
		if (map->map[i][0] == '#')
			map->st = i;
		else if (map->map[i][0] == 'L')
			map->en = i;
		i++;
	}
	return (*map);
}

void		print_matrix(int **intmap, int size)
{
	int i = 0;
	int j = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			printf("%d ", intmap[i][j]);
			j++;
		}
		i++;
	}
}

void		path_find(int **map, int start, int end, int size)
{
	int i;
	int	j;
	int *stack;
	int	top;

	stack = malloc(sizeof(int) * size * size);
	top = -1;
	i = start;
	while (i != end)
	{
		j = 0;
		while (j < size - 1)
		{
			if (map[i][j] == 1)
			{
				push(stack, &top, j);
				map[i][j] = 0;
				i = j;
				j = 0;
				continue ;
			}
			if (map[i][j] == 0 && j == size - 1)
			{
				printf("top before:%d\n", top);
				pop(stack);
				printf("after now%d\n", top);
				i = stack[top];
				j = 0;
			}
			j++;
		}
		printf("%d", i);
		break ;
	}
}

void		complete_int_map(t_lemin map, int **intmap)
{
	int i;
	int j;

	j = 0;
	i = 0;

	map_check(&map);
	path_find(intmap, map.st, map.en, map.s);
	printf("HERE YOU GO --- %d, %d --- \n", map.st, map.en);
	while (i < map.s)
	{
		printf("%s\n", map.map[i]);
		i++;
	}
	i = 0;
	printf("%lu\n", map.ant);
	while (i < map.s)
	{
		while (j < map.s)
		{
			printf("%d ", intmap[i][j]);
			j++;
		}
	i++;
	j = 0;
	printf("\n");
	}
}
