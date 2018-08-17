/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaplan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 13:19:16 by dkaplan           #+#    #+#             */
/*   Updated: 2018/08/17 07:58:22 by dkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/lemin.h"
#include <stdio.h>

void		complete_int_map(t_lemin map, int **intmap)
{
	int i = 0;
	(void)intmap;
	while (i < map.count[0])
	{
		printf(">>>>%s<<<<\n", map.in[i]);
		i++;
	}
}
