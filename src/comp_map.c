/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaplan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 13:19:16 by dkaplan           #+#    #+#             */
/*   Updated: 2018/08/23 08:32:31 by dkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"
#include <stdio.h>

void		print_int_arr(int *arr, int size)
{
	int i = 0;
	while (i <= size)
	{
		printf("%d - ", arr[i]);
		i++;
	}
}

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

int		intro_path_finder(int **stack, int *top, int start, int size)
{
	*stack = malloc(sizeof(int) * size * size);
	*top = -1;
	return (start);
}



t_stack		path_find_iter(int **map, int start, int end, int size)
{
	t_stack s;

	s.i = intro_path_finder(&s.stack, &s.top, start, size);
	while (s.i != end)
	{
		s.j = 0;
		while (s.j <= size - 1)
		{
			if (map[s.i][s.j] == 1)
			{
				push(s.stack, &s.top, s.j);
				map[s.i][s.j] = 0;
				s.i = s.j;
			}
			else if (map[s.i][s.j] == 0 && s.j == size - 1)
			{
				pop(&s.top);
				s.i = s.stack[s.top];
				break ;
			}
			s.j = map[s.i][s.j] == 1 ? 0 : s.j + 1;
		}
	}
	return (s);
}

void		complete_int_map(t_lemin map, int **intmap)
{
	int i;
	int j;
	t_stack stack;

	j = 0;
	i = 0;
	map_check(&map);
	stack = path_find_iter(intmap, map.st, map.en, map.s);
	printf("%d", stack.i);
	print_int_arr(stack.stack, stack.top);
	printf("HERE YOU GO --- %d, %d --- \n", map.st, map.en);
	/*while (i < map.s)
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
	}*/
}
