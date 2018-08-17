/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaplan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 13:19:16 by dkaplan           #+#    #+#             */
/*   Updated: 2018/08/17 12:10:33 by dkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"
#include <stdio.h>

void		complete_int_map(t_lemin map, int **intmap)
{
	int i;
	int j;

	j = 0;
	i = 0;
	printf("%d\n", map.s);;
	while (i < 8)
	{
		while (j < 8)
		{
			printf("%d ", intmap[i][j]);
			j++;
		}
	i++;
	j = 0;
	printf("\n");
	}
}
