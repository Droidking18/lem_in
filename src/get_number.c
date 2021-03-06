/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_number.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaplan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 11:56:54 by dkaplan           #+#    #+#             */
/*   Updated: 2018/08/27 11:33:14 by dkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"
#include <stdio.h>

int				check_invalid(char *str)
{
	int i;

	i = 0;
	if (ft_strcmp(str, "squish all") == 0)
		std_err(RED" : all ants are now dead. Hope you're happy.\n");
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

t_lemin			get_number(void)
{
	t_lemin	map;

	map.count[0] = 0;
	map.in = malloc_2d(map.in);
	map.ant = 0;
	while (get_next_line(0, &map.in[map.count[0]]))
	{
		if (check_comment(map.in[map.count[0]]) == 1
				|| check_comment(map.in[map.count[0]]) == 4)
		{
			map.count[0]++;
			map.ant = 0;
		}
		else if (check_invalid(map.in[map.count[0]]) == 1)
			std_err(RED" : number of ants must be a digit.\n");
		else
		{
			map.ant = ft_atoi(map.in[map.count[0]]);
			break ;
		}
	}
	map.count[0]++;
	if (map.ant > 2147483647 || map.ant < -2147483648 || !map.ant)
		std_err(RED" : ants can not overflow, nor can they be 0.\n");
	return (map);
}
